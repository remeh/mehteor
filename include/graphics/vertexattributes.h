#ifndef MEH_VERTEXATTRIBUTES_H
#define MEH_VERTEXATTRIBUTES_H

#include <vector>
#include "GL/glew.h"
#include "graphics/vertexattribute.h"
#include "graphics/shaderprogram.h"

using namespace std;

namespace meh {

class VertexAttributes {
    public: // static
        static string positionAttribute;
        static string textureCoordinatesAttribute;

    private:
        vector<VertexAttribute> attributes;

        int totalDim;
        int ffset;

    protected:
    public:
        VertexAttributes();

        void addAttribute(VertexAttribute attr);

        /*
         * NOTE: assumes GL_FLOAT
         */
        void enable(ShaderProgram& shaderProgram); 

        /**
         * The total dimension of these vertices (every components of every attributes added).
         * @return the total dimension of these vertices.
         */
        int totalDimension() {
            return totalDim;
        }
};

}

#endif // MEH_VERTEXATTRIBUTES_H

