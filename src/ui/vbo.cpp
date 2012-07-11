#include <cstring> // memcpy
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "ui/vbo.h"

using namespace std;

namespace meh {

GLuint VBO::positionAttribute = 0;
GLuint VBO::textureAttribute = 1;

VBO::VBO(unsigned int size, unsigned int dimension, float* vertices) :
    sze(size),
    dim(dimension) {
    unsigned int totalSize = size*dimension;
    vrtices = new float[totalSize];
    // TODO use a memcpy
    //memcpy(vrtices, vertices, totalSize);
    for (unsigned int i = 0; i < totalSize; i++) {
        vrtices[i] = vertices[i];
    }
    glGenBuffers(1, &vboId);
    vrtexAttributes.addAttribute(VertexAttribute(dimension,VertexAttributes::positionAttribute));
    // The vertices will be upload on the GPU on the first call of bind(ShaderProgram)
    drty = true;
}

VBO::~VBO() {
    glDeleteBuffers(1,&vboId);
    delete[] vrtices;
}

void VBO::bind(ShaderProgram* shaderProgram) {
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    if (drty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(dim*sze)*sizeof(GLfloat), vrtices, GL_STATIC_DRAW);
        printf("Uploaded data to the GPU.\n");
        drty = false;
    }

   vrtexAttributes.enable(shaderProgram); 
}

}

