#ifndef MEH_VBO_H
#define MEH_VBO_H

#include "GL/glew.h"
#include "graphics/shaderprogram.h"
#include "graphics/vertexattributes.h"

namespace meh {

class VBO {
    private:
        unsigned int sze;
        unsigned int dim;

        GLfloat* vrtices;

        /**
         * OpenGL VBO id.
         */
        GLuint vboId;

        /**
         * Whether the data on the GPU isn't correct, this VBO is dirty and
         * the next bind will make a call to glBufferData to send the vertices
         * to the GPU.
         */
        bool drty;

        VertexAttributes vrtexAttributes;

        /**
         * When this VBO is dynamic, we should use GL_DYNAMIC_DRAW instead of GL_STATIC_DRAW
         */
        bool dyn;

    protected:
    public:
        /**
         * Creates a VBO containing 'size' vertex of 'dimension'.
         * The content of the vertices data is copied.
         *
         * @param dynamic whether this VBO is dynamic (vertices will regularly change).
         */
        VBO(bool dynamic = false);
        ~VBO();

        /**
         * Binds the VBO to the current target buffer.
         */
        void bind();

        /**
         * Unbinds the VBO.
         */
        void unbind();

        /**
         * Sets the vertices of this VBO.
         *
         * @param size number of vertices.
         * @param dimension dimension of a vertex.
         * @param vertices vertices data. A copy of the data is done.
         */
        void setVertices(unsigned int size, unsigned int dimension, GLfloat* vertices);

        const unsigned int getSize()
        {
            return sze;
        }

        const unsigned int getDimension()
        {
            return dim;
        }
};

} // namespace meh

#endif // MEH_VBO_H
