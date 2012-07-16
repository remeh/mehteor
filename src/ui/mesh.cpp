#include "ui/mesh.h"
#include "GL/glew.h"

namespace meh {

Mesh::Mesh(VertexAttributes attributes) :
    attributes(attributes),
    vbo(nullptr) {
}

Mesh::~Mesh() {
    deleteVBO();
}

void Mesh::setVertices(int size, int dimension, GLfloat* vertices) {
    deleteVBO();
    vbo = new VBO(size,dimension,vertices);
}

void Mesh::deleteVBO() {
    if (!vbo) {
        delete vbo;
        vbo = nullptr;
    }
}

void Mesh::bind(ShaderProgram& shaderProgram) {
    vbo->bind(shaderProgram);
    attributes.enable(shaderProgram);
}

void Mesh::render(ShaderProgram& shaderProgram) {
    shaderProgram.enable();
    glDrawArrays(GL_TRIANGLES, 0, vbo->size());
}

} // namespace meh
