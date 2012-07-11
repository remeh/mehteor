#ifndef MEH_VERTEXATTRIBUTES_H
#define MEH_VERTEXATTRIBUTES_H

#include <vector>
#include "GL/glew.h"
#include "ui/vertexattribute.h"
#include "ui/shaderprogram.h"

using namespace std;

namespace meh {

class VertexAttributes {
    public:
        static string positionAttribute;

    private:
        vector<VertexAttribute> attributes;

    protected:
    public:
        VertexAttributes();

        void addAttribute(VertexAttribute attr);

        /*
         * NOTE: assumes GL_FLOAT
         */
        void enable(ShaderProgram* shaderProgram); 
};

}

#endif // MEH_VERTEXATTRIBUTES_H

