#ifndef MEH_VBO_H
#define MEH_VBO_H

#include "GL/glew.h"
#include "ui/shaderprogram.h"
#include "ui/vertexattributes.h"

namespace meh {

class VBO {
    private:
        unsigned int sze;
        unsigned int dim;

        float* vrtices;

        /**
         * OpenGL VBO id.
         */
        GLuint vboId;

        static GLuint positionAttribute;
        static GLuint textureAttribute;

        void bind();

        /**
         * Whether the data on the GPU isn't correct, this VBO is dirty and
         * the next bind will make a call to glBufferData to send the vertices
         * to the GPU.
         */
        bool drty;

        VertexAttributes vrtexAttributes;

    protected:
    public:
        /**
         * Creates a VBO containing 'size' vertex of 'dimension'.
         * The content of the vertices data is copied.
         *
         * @param size number of vertices.
         * @param dimension dimension of a vertex.
         * @param vertices vertices data. A copy of the data is done.
         */
        VBO(unsigned int size, unsigned int dimension, float* vertices);
        ~VBO();

        /**
         * Binds the VBO to the current target buffer.
         */
        void bind(ShaderProgram* shaderProgram);
};

}

#endif // MEH_VBO_H
