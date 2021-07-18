// fractals add-in by davidovski
// Copyright (C) 2021 davidovski
//
// This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include <gint/gint.h>
#include <gint/display.h>
#include <gint/keyboard.h>
#include <gint/keycodes.h>

typedef struct vec2 {
	float x;
	float y;
} vec2;


vec2 offset = {0, 0};
vec2 poi = {1.5f, 0.5f};


vec2 screen = {128, 64};

float zoom = 2.0f;
float max = 40.0f;

vec2 add(vec2 a, vec2 b) {
	vec2 r = {a.x + b.x, a.y + b.y};
	return r;
}

double dot(vec2 a, vec2 b) {
    return  a.x*b.x + a.y+b.y;
}

vec2 compsquare(vec2 z) {
	float temp = z.x;
	z.x = z.x*z.x - z.y*z.y;
	z.y = 2.0*temp*z.y;
	return z;
}

bool mandelbrot(vec2 point) {
	vec2 z = {0, 0};
	for (float iters = 0.0f; iters < max; ++iters) {
		vec2 sq = compsquare(z);
		z.x = sq.x + point.x;
		z.y = sq.y + point.y;
		z.x = sq.x + point.x;

		if (dot(z, z) > 4.0) return false;
	}
	return true;
}

int main(void) {
	gint_setrestart(1);
	while (true) {
		getkey();
		dclear(C_WHITE);
		for (float x = 0; x < 128; x++) {
			for (float y = 0; y < 64; y++) {
				vec2 point = {x / screen.x, y / screen.y};
				point.x *= screen.x / screen.y;
				
				point.x -= poi.x;
				point.y -= poi.y;
				
				point.x *= zoom;
				point.y *= zoom;

				point.x -= offset.x;
				point.y -= offset.y;

				if (mandelbrot(point)) {
					dpixel(x , y, C_BLACK);
				}
				dupdate();
			}
		} 
		
		drect(1, 1, 3, 3, C_BLACK);
		dupdate();

		getkey();

		if (keydown(KEY_ADD)) zoom -= zoom * 0.2f;
		if (keydown(KEY_SUB)) zoom += zoom * 0.2f;
		
		if (keydown(KEY_UP)) offset.y -= zoom * 0.1f;
		if (keydown(KEY_DOWN)) offset.y += zoom * 0.1f;
		if (keydown(KEY_RIGHT)) offset.x -= zoom * 0.1f;
		if (keydown(KEY_LEFT)) offset.x += zoom * 0.1f;
		
		if (keydown(KEY_EXIT)) gint_osmenu();

	}
	return 0;
}
