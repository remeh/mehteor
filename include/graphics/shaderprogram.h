#ifndef MEH_SHADERPROGRAM_H
#define MEH_SHADERPROGRAM_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "core/vector2d.h"

#include "ui/shader.h"

using namespace std;

namespace meh {

class ShaderProgram {
    private:
        GLuint shaderProgramId;
        list<Shader*> shders;
        
    protected:
    public:
        ShaderProgram();

        void addShader(Shader* s);

        void link();

        void enable();

        void disable();

        void enableVertexAttribute(string name);

        void sizeOneVertex();

        void setVertexAttribute(string name, int dimension, int offset, int dimVertex, int type, bool normalize);

        const GLuint id() {
            return shaderProgramId;
        }
};

}

#endif // MEH_SHADERPROGRAM_H
