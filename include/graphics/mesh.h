#ifndef MEH_MESH_H
#define MEH_MESH_H

#include "graphics/vbo.h"
#include "graphics/ibo.h"
#include "graphics/vertexattributes.h"
#include "graphics/shaderprogram.h"
#include "GL/glew.h"

namespace meh {

class Mesh {
    private:
        VertexAttributes attributes;
        VBO* vbo;
        IBO* ibo;

    protected:
    public:
        Mesh(VertexAttributes attributes);
        ~Mesh();

        void setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices);
        void deleteVBO();

        void setElements(unsigned int size, unsigned int dimension, GLuint* elements);
        void deleteIBO();

        void bind(ShaderProgram& shaderProgram);
        void unbind();
        void render(ShaderProgram& shaderProgram);
};

}

#endif // MEH_MESH_H
