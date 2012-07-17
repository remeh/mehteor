#include <cstdio>
#include "ui/ibo.h"

namespace meh {

IBO::IBO(bool dynamic) :
    drty(true),
    elems(nullptr),
    sze(0),
    dim(0),
    dyn(dynamic) {
    glGenBuffers(1,&iboId);
}

IBO::~IBO() {
    glDeleteBuffers(1,&iboId);
}

void IBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    if (drty) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sze*dim*sizeof(GLuint), elems, dyn ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
    }
    printf("IBO binded : %i\n",iboId);
}

void IBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    printf("IBO unbinded : %i\n",iboId);
}

void IBO::setElements(unsigned int size, unsigned int dimension, GLfloat* elements) {
    sze = size;
    dim = dimension;

    // Delete old values if any
    if (elems) {
        delete[] elems;
        elems = nullptr;
    }
    // Store new values
    int totalSize = sze*dim;
    elems = new GLfloat[totalSize];
    // TODO use memcpy
    for (int i =0; i < totalSize; i++) {
        elems[i] = elements[i];
    }
    drty = true;
}

}
