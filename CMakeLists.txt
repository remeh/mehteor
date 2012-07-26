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
        src/graphics/camera.cpp
        src/graphics/orthographiccamera.cpp
# engine
        src/engine/inputdevicesmanager.cpp
        src/engine/resourcesmanager.cpp
        src/engine/sprite.cpp
        src/engine/spriterenderer.cpp

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

#if(WIN32)
#set(CMAKE_C_COMPILER i486-mingw32-gcc)
#set(CMAKE_CXX_COMPILER i486-mingw32-g++)
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#endif(WIN32)

# Search in the `cmake' directory for additional CMake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# dependency checking
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeTests)
include(FindSDL REQUIRED)
include(FindOpenGL REQUIRED)
#include(FindGLEW REQUIRED)

#if (NOT GLFW_FOUND)
#    message(FATAL_ERROR "glfw not found")
#    else()
#    include_directories(${GLFW_INCLUDE_DIRS})
#endif()

include_directories(${SDL_INCLUDE_DIR})

# g++ flags
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

# sources
include_directories(${Mehteor_SOURCE_DIR}/include)
link_directories(${Mehteor_BINARY_DIR}/src)
link_libraries (
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY} # if using SDL_image, obviously
    SDLmain # Sadly not included in SDL_LIBRARY variable
    ${OPENGL_LIBRARY} # if using SDL_image, obviously
)
add_executable(
    main 
    WIN32
    ${MEHTEOR_SOURCES}
)
