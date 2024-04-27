# Shrub
OpenGL-based low-level library for making game.

## What is this?
Inspired by [raylib](https://github.com/raysan5/raylib), this library tries to reduce boilerplate code when working with OpenGL and add some much-needed functionalities.

## Features
- **tngl**: Low-level wrapper for modern OpenGL.
- **shrub**: C++ wrapper for windowing, audio, and resource management.
- **shruberry**: High-level OpenGL renderer.

Most of these features are still work in progress, as is this library. Follow this table for intended features and progresses on it:

|Feature|Status|
|:-:|:-:|
|tngl|:construction:|
|shrub|:construction:|
|shruberry|:construction:|


## Dependencies
I literally did not do a thing and just depends on these:
- [glad](https://github.com/Dav1dde/glad) for OpenGL
- [glfw](https://github.com/glfw/glfw) for window creation and input
- [stb](https://github.com/nothings/stb) for image handling
- [miniaudio](https://github.com/mackron/miniaudio) for audio

## How to use
Currently this uses CMake for building. The expectation is to use the `include` folder.

## License
