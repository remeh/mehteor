CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Mehteor)

set(
        MEHTEOR_SOURCES
# core
        src/core/system.cpp
        src/core/bytebuffer.cpp
# graphics
        src/graphics/canvas.cpp
        src/graphics/shader.cpp
        src/graphics/shaderprogram.cpp
        src/graphics/vbo.cpp
        src/graphics/ibo.cpp
        src/graphics/texture.cpp
        src/graphics/bitmap.cpp
        src/graphics/vertexattributes.cpp
        src/graphics/vertexattribute.cpp
        src/graphics/mesh.cpp
# engine
        src/engine/inputdevicesmanager.cpp
        src/engine/resourcesmanager.cpp
        src/engine/sprite.cpp
        src/engine/spriterenderer.cpp
        src/engine/spriteanimation.cpp
        src/engine/camera/camera.cpp
        src/engine/camera/orthographiccamera.cpp
        src/engine/scene/simplescene2d.cpp
        src/engine/scene/spriteactor.cpp

# tests
        src/tests/testsmatrix4x4f.cpp
# SOIL
        src/soil/image_DXT.c
        src/soil/image_helper.c
        src/soil/SOIL.c
        src/soil/stb_image_aug.c
# GLEW
        src/glew.c
# Main
     src/main.cpp
#       src/tests.cpp
)

# Search in the `cmake' directory for additional CMake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# dependency checking
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeTests)
include(FindSDL REQUIRED)
include(FindOpenGL REQUIRED)
#include(FindGLEW REQUIRED)


include_directories(${SDL_INCLUDE_DIR})

if (WIN32 OR MINGW)
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -DGLEW_STATIC -DWIN32 -D_WIN32")
    set(CMAKE_C_FLAGS "-g -Wall -DGLEW_STATIC -DWIN32 -D_WIN32")
else()
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -DGLEW_STATIC")
    set(CMAKE_C_FLAGS "-g -Wall -DGLEW_STATIC")
endif()

# g++ flags

# sources
include_directories(${Mehteor_SOURCE_DIR}/include)
link_directories(${Mehteor_BINARY_DIR}/src)
link_libraries (
    ${SDL_LIBRARY}
    SDLmain # Sadly not included in SDL_LIBRARY variable
    ${OPENGL_LIBRARY} 
)

add_executable(
    main 
    ${MEHTEOR_SOURCES}
)

