#ifndef MEH_MESH_H
#define MEH_MESH_H

#include "ui/vbo.h"
#include "ui/vertexattributes.h"
#include "ui/shaderprogram.h"
#include "GL/glew.h"

namespace meh {

class Mesh {
    private:
        VertexAttributes attributes;
        VBO* vbo;

    protected:
    public:
        Mesh(VertexAttributes attributes);
        ~Mesh();

        void setVertices(int size, int dimension, GLfloat* vertices);
        void deleteVBO();

        void bind(ShaderProgram& shaderProgram);
        void render(ShaderProgram& shaderProgram);
};

}

#endif // MEH_MESH_H
