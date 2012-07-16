CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Mehteor)

set(
        MEHTEOR_SOURCES
# core
        src/core/system.cpp
        src/core/bytebuffer.cpp
# ui
        src/ui/canvas.cpp
        src/ui/shader.cpp
        src/ui/shaderprogram.cpp
        src/ui/vbo.cpp
        src/ui/texture.cpp
        src/ui/bitmap.cpp
        src/ui/vertexattributes.cpp
        src/ui/vertexattribute.cpp
        src/ui/mesh.cpp
# SOIL
        src/soil/image_DXT.c
        src/soil/image_helper.c
        src/soil/SOIL.c
        src/soil/stb_image_aug.c
# GLEW
        src/glew.c
        src/glew.c
# Main
        src/main.cpp
)

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
    ${MEHTEOR_SOURCES}
)
