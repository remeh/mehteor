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
    public: // static
        static string positionAttribute;
        static string textureCoordinateAttribute;
        static string colorAttribute;

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

        void setVertexAttribute(string name, int dimension, int type, bool normalize);

        const GLuint id() {
            return shaderProgramId;
        }
};

}

#endif // MEH_SHADERPROGRAM_H
