#include "ui/mesh.h"
#include "GL/glew.h"

namespace meh {

Mesh::Mesh(VertexAttributes attributes) :
    attributes(attributes),
    vbo(nullptr),
    ibo(nullptr) {
}

Mesh::~Mesh() {
    deleteVBO();
}

void Mesh::setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices) {
    deleteVBO();
    vbo = new VBO(false); // TODO assume static for the moment
    vbo->setVertices(size, dimension, vertices);
}

void Mesh::setElements(unsigned int size, unsigned int dimension, GLfloat* vertices) {
    deleteIBO();
    ibo = new IBO(false); // TODO assume static for the moment
    ibo->setElements(size,dimension,vertices);
}

void Mesh::deleteVBO() {
    if (vbo) {
        delete vbo;
        vbo = nullptr;
    }
}

void Mesh::deleteIBO() {
    if (!ibo) {
        delete ibo;
        ibo = nullptr;
    }
}

void Mesh::bind(ShaderProgram& shaderProgram) {
    vbo->bind(shaderProgram);
    if (ibo) {
        ibo->bind();
    }
    attributes.enable(shaderProgram);
}

void Mesh::render(ShaderProgram& shaderProgram) {
    shaderProgram.enable();
    if (ibo) {
        // TODO offset
        glDrawElements(GL_TRIANGLES, ibo->size(), GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, vbo->size());
    }
}

void Mesh::unbind() {
    if (ibo) {
        ibo->unbind();
    }
    vbo->unbind();
}

} // namespace meh
