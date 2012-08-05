#include <cstring> // memcpy
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "graphics/vbo.h"

using namespace std;

namespace meh {

GLuint VBO::positionAttribute = 0;
GLuint VBO::textureAttribute = 1;

VBO::VBO(bool dynamic) :
    vrtices(nullptr), 
    drty(true),
    dyn(dynamic) {
    glGenBuffers(1, &vboId);
}

VBO::~VBO() {
    glDeleteBuffers(1,&vboId);
    if (vrtices) {
        delete[] vrtices;
        vrtices = nullptr;
    }
}

void VBO::setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices) {
    sze = size;
    dim = dimension;

    // Releases old version if any
    if (vrtices) {
        delete[] vrtices;
        vrtices = nullptr;
    }

    unsigned int totalSize = size*dimension;
    vrtices = new GLfloat[totalSize];
    // Copy the values
    // memcpy(vrtices, vertices, totalSize); // XXX doesn't work on both my computers!
    for (unsigned int i = 0; i < totalSize; i++) {
        vrtices[i] = vertices[i];
    }

    drty = true;
}

void VBO::bind(ShaderProgram& shaderProgram) {
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    if (drty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*sze*dim, vrtices, dyn ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
        drty = false;
    }
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER,vboId);
}

}

