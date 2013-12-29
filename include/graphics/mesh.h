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
        /**
         * Vertex definition.
         */
        VertexAttributes attributes;

        VBO* vbo;
        IBO* ibo;

    protected:
    public:
        /**
         * Constructs a Mesh.
         * @param attriutes format of this mesh's vertices
         */
        Mesh(VertexAttributes attributes);

        ~Mesh();

        /**
         * Sets the vertices of this Mesh. 
         * The VBO becomes invalidated and will be re-uploaded onto the GPU when needed.
         *
         * @param size how many vertices composed this Mesh. 
         * @param dimension the dimension of one vertex of this Mesh.
         * @param vertices the vertices composing this Mesh.
         */
        void setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices);

        /**
         * Deletes this Mesh's VBO.
         */
        void deleteVBO();

        /**
         * Sets the elements of this Mesh.
         * The IBO becomes invalidated and will be re-uploaded onto the GPU when needed.
         *
         * @param size how many elements composed this Mesh. 
         * @param dimension the dimension of one element of this Mesh.
         * @param vertices the elements describing the vertices of this Mesh.
         */
        void setElements(unsigned int size, unsigned int dimension, GLuint* elements);

        /**
         * Deletes this Mesh's IBO.
         */
        void deleteIBO();

        /**
         * Binds this Mesh to be rendered.
         *
         * @param shaderProgram which shader program will be used to render this Mesh.
         */
        void bind(ShaderProgram& shaderProgram);
        /**
         * Unbinds this Mesh.
         */
        void unbind();

        /**
         * Renders this Mesh.
         */
        void render();
};

}

#endif // MEH_MESH_H
