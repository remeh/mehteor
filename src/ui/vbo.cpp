#include <cstring> // memcpy
#include <cstdio> // printf
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "ui/vbo.h"

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
    // TODO use a memcpy
    // memcpy(vrtices, &vertices, totalSize);
    for (unsigned int i = 0; i < totalSize; i++) {
        vrtices[i] = vertices[i];
    }

    drty = true;
}

void VBO::bind(ShaderProgram& shaderProgram) {
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    if (drty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*sze*dim, vrtices, dyn ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
        printf("Uploaded vertices data to the GPU.\n");
        drty = false;
    }
    printf("VBO binded : %i\n",vboId);
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER,vboId);
    printf("VBO unbinded : %i\n",vboId);
}

}

