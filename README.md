Mehteor
=======

A C++ OpenGL 2.1 Game engine - in progress!

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
