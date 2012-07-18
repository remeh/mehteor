#ifndef MEH_SHADERPROGRAM_H
#define MEH_SHADERPROGRAM_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "core/vector2d.h"

#include "graphics/shader.h"
#include "core/matrix4x4.h"

using namespace std;

namespace meh {

class ShaderProgram {
    private:
        GLuint shaderProgramId;
        list<Shader*> shders;

        /**
         * Returns the location of the attribute in the ShaderProgram, -1 if not found.
         * @return the location of the attribute in the ShaderProgram, -1 if not found. 
         */
        int fetchUniformLocation(string name);
        
    protected:
    public:
        ShaderProgram();

        /**
         * Adds a Shader to this ShaderProgram.
         * @param s the shader to add.
         */
        void addShader(Shader* s);

        /**
         * Links the ShaderProgram.
         */
        void link();

        /**
         * Activates this ShaderProgram.
         */
        void enable();

        /**
         * Disables this ShaderProgram.
         */
        void disable();

        /**
         * Enables a vertex attribute.
         */
        void enableVertexAttribute(string name);

        /**
         * Specifies the struct of a kind of vertex attributes.
         */
        void setVertexAttribute(string name, int dimension, int offset, int dimVertex, int type, bool normalize);

        const GLuint id() {
            return shaderProgramId;
        }

        // Params functions TODO comment

        void setUniformi(string name, int value);
        void setUniformi(string name, int value1, int value2);
        void setUniformi(string name, int value1, int value2, int value3);
        void setUniformi(string name, int value1, int value2, int value3, int value4);

        void setUniformf(string name, float value);
        void setUniformf(string name, float value, float value2);
        void setUniformf(string name, float value, float value2, float value3);
        void setUniformf(string name, float value, float value2, float value3, float value4);

        void setUniform1iv(string name, int count, int* values);
        void setUniform2iv(string name, int count, int* values);
        void setUniform3iv(string name, int count, int* values);
        void setUniform4iv(string name, int count, int* values);

        void setUniform1fv(string name, int count, float* values);
        void setUniform2fv(string name, int count, float* values);
        void setUniform3fv(string name, int count, float* values);
        void setUniform4fv(string name, int count, float* values);
    
        void setUniformMatrix4x4(string name, Matrix4x4<float>& matrix, bool transpose = false);
};

}

#endif // MEH_SHADERPROGRAM_H
