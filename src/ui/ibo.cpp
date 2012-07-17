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
    if (elems) {
        delete[] elems;
        elems = nullptr;
    }
}

void IBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    if (drty) {
        printf("Uploaded elements data to the GPU.\n");
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*sze*dim, elems, dyn ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
        drty = false;
    }
    printf("IBO binded : %i\n",iboId);
}

void IBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    printf("IBO unbinded : %i\n",iboId);
}

void IBO::setElements(unsigned int size, unsigned int dimension, GLuint* elements) {
    sze = size;
    dim = dimension;

    // Delete old values if any
    if (elems) {
        delete[] elems;
        elems = nullptr;
    }
    // Store new values
    int totalSize = sze*dim;
    elems = new GLuint[totalSize];
    // TODO use memcpy
    for (int i =0; i < totalSize; i++) {
        elems[i] = elements[i];
    }
    drty = true;
}

}
