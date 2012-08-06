#include <cstdio>
#include <cstring> // memcpy
#include "graphics/ibo.h"

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
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*sze*dim, elems, dyn ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
        drty = false;
    }
}

void IBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void IBO::setElements(unsigned int size, unsigned int dimension, GLuint* elements) {
    int totalSize = size*dimension;
    // Reallocate the memory only when needed
    if (!elems || sze != size || dim != dimension) {
        sze = size;
        dim = dimension;

        // Delete old values if any
        if (elems) {
            delete[] elems;
            elems = nullptr;
        }
        // Store new values
        elems = new GLuint[totalSize];
    }

    memcpy(elems,elements,totalSize);

    drty = true;
}

}
