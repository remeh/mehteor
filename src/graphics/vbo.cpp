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
    vboId(0),
    drty(true),
    dyn(dynamic) {
    glGenBuffers(1, &vboId);
    printf("new VBO\n");
}

VBO::~VBO() {
    if (vboId > 0) {
        glDeleteBuffers(1,&vboId);
        vboId = 0;
    }
    if (vrtices) {
        delete[] vrtices;
        vrtices = nullptr;
    }
}

void VBO::setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices) {
    unsigned int totalSize = size*dimension;

    // We reallocate the memory only if it's not the same size
    if (!vrtices || size != sze || dimension != dim) {
        sze = size;
        dim = dimension;

        // Releases old version if any
        if (vrtices) {
            delete[] vrtices;
            vrtices = nullptr;
        }

        vrtices = new GLfloat[totalSize];
    }

    // Copy the values
    memcpy(vrtices, vertices, totalSize);

    drty = true;
}

void VBO::bind() {
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

