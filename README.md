Mehteor
=======

A multiplatform C++ OpenGL 2/3 Game engine.

Current features :

    * accelerated 2d scenes (texturing, cameras, sprites, animated sprite),
    * accelerated font rendering (ATM through image atlases),
    * sound with OpenAL,
    * many utility classes (vectors, matrices, quaternions, rects, byte buffers, ...),
    * keyboard/mouse input,
    * JSON reading/writing,
    * threading support.

Roadmap
=======

The goal of the final 1.0 is to have a 2D game engine capable of rendering many animated sprites, with text, sounds and keyboard/mouse inputs.
This goal is nearly reached as I finish / optimize some of these tasks, but there all currently working.

### 1.0-RC2

```
- the mouse click is sometimes ignored (IMO the input system must be redone)
- semaphores, thread helpers (synchronized methods ?)
```

### 1.0-RC3

```
- improve 2d rendering performances
- sprite flipX/flipY, rotation and scale
- helper in sprites to increase/decrease opacity, to read a tint from vector4d, ...
- maybe less inline methods ?
```

### 1.0

```
- use meh::Thread instead of SDL_Thread in `audio/audiosystem`
- `bytebuffer.cpp` : more functions read/write
- target for unit tests + unit tests!
```

### Next

```
- create font atlas with SDL_ttf 2.0
- gamepads support
```

Build (Linux and Mac)
=======

- Needed dependencies : SDL, OpenGL, OpenAL, libvorbis, libogg and CMake
- Download mehteor : git clone https://github.com/remeh/mehteor
- cd mehteor
- mkdir build && cd build
- cmake ../ && make

A toolchain to build for Windows is in the cmake/ directory, but was only tested from Linux (cross-compiling).

Included dependencies 
=======

Mehteor includes :
 - GLEW version included 1.8.0 from the official website : http://glew.sourceforge.net/
 - SOIL version included July 7, 2008 from the official website : http://lonesock.net/soil.html
 - Json-Cpp version 0.6.0-rc2 retrieved from the Github repo : https://github.com/mrtazz/json-cpp
 - TinyThreadpp : cloned the repository, last modification was on nov 6th 2012 : https://gitorious.org/tinythread/tinythreadpp/
