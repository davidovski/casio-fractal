# Mandelbrot Casio

An attempt at rendering the mandelbrot set fractal using [gint](https://gitea.planet-casio.com/Lephenixnoir/gint) for the fx series casio calculators.

At the moment I am using a (probably) very inefficient algorithm for calcualting the mandelbrot set, so if you happen to know how to optimise this, feel free to!

I would advise overclocking your calculator using a tool such as [ftune](http://pm.matrix.jp/ftune2e.html) to help with performance.

## Controls

- \+ zoom in
- \- zoom out
- ↑ pan up
- ↓ pan down
- ← pan left
- → pan right

## Building

I would reccomend using [fxsdk](https://gitea.planet-casio.com/Lephenixnoir/fxsdk) to build this:

`fxsdk build-fx`

inside the project directory
