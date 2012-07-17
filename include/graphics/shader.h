#ifndef MEH_SHADER_H
#define MEH_SHADER_H

#include <string>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "core/vector2d.h"

using namespace std;

namespace meh {

class Shader {
    public:
        typedef enum {
            VERTEX_SHADER = 0,
            FRAGMENT_SHADER = 1
        } ShaderType;

    private:
        string shader;

        /**
         * Is this shader correctly loaded and ready to use.
         */
        bool loaded;

        ShaderType tpe;

        GLuint shaderId;

        GLuint positionAttrib;

    protected:
    public:
        /**
         * Creates a Shader with the content of a file.
         * 
         * @param file creates the shader with the content of this file.
         */
        Shader(string file, ShaderType type);

        ShaderType type() {
            return tpe;
        }

        const GLuint id() {
            return shaderId;
        }

};

}

#endif // MEH_SHADER_H
