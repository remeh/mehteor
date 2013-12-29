#include "graphics/mesh.h"
#include "GL/glew.h"

namespace meh {

Mesh::Mesh(VertexAttributes attributes) :
    attributes(attributes),
    vbo(nullptr),
    ibo(nullptr)
{
}

Mesh::~Mesh() 
{
    deleteVBO();
    deleteIBO();
}

void Mesh::setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices) 
{
    if (vbo) 
    {
        if (vbo->getSize() != size || vbo->getDimension() != dimension) 
        {
            deleteVBO();
            vbo = new VBO(false); // TODO assume static for the moment
        }
    }
    else 
    {
        vbo = new VBO(false);
    }
    vbo->setVertices(size, dimension, vertices);
}

void Mesh::setElements(unsigned int size, unsigned int dimension, GLuint* elements) 
{
    if (ibo) 
    {
        if (ibo->getSize() != size || ibo->getDimension() != dimension)
        {
            deleteIBO();
            ibo = new IBO(false); // TODO assume static for the moment
        }
    } 
    else
    {
        ibo = new IBO(false);
    }
    ibo->setElements(size,dimension,elements);
}

void Mesh::deleteVBO()
{
    if (vbo)
    {
        delete vbo;
        vbo = nullptr;
    }
}

void Mesh::deleteIBO()
{
    if (ibo)
    {
        delete ibo;
        ibo = nullptr;
    }
}

void Mesh::bind(ShaderProgram& shaderProgram) 
{
    vbo->bind();
    if (ibo)
    {
        ibo->bind();
    }
    attributes.enable(shaderProgram);
}

void Mesh::render()
{
    if (ibo)
    {
        // TODO offset
        glDrawElements(GL_TRIANGLES, ibo->getDimension()*ibo->getSize(), GL_UNSIGNED_INT, 0);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, vbo->getSize());
    }
}

void Mesh::unbind()
{
    if (ibo)
    {
        ibo->unbind();
    }
    vbo->unbind();
}

} // namespace meh
