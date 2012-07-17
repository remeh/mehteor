#include "ui/shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include "GL/glew.h"

using namespace std;

namespace meh {

Shader::Shader(string file, ShaderType type) :
    loaded(false),
    shaderId(-1) {
    ifstream f;
    f.open(file.c_str());

    if (f) {
        stringstream stream;
        stream << f.rdbuf();
        f.close();
        shader = stream.str();

        tpe = type;

        switch (type) {
            case VERTEX_SHADER:
                shaderId = glCreateShader(GL_VERTEX_SHADER);
                break;
            case FRAGMENT_SHADER:
                shaderId = glCreateShader(GL_FRAGMENT_SHADER);
                break;
        }

        const GLchar* c = shader.c_str();
        glShaderSource(shaderId, 1, &c, NULL);
        glCompileShader(shaderId);

        // Check whether the compilation succeed
        GLint compileStatus;
        glGetShaderiv(shaderId,GL_COMPILE_STATUS,&compileStatus);

        if (compileStatus == GL_TRUE) {
            // everything went fine, the shader is loaded
            loaded = true;
        } else {
            // doesn't seem ok, display the log
            GLint length;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
            char* log = new char[length]; 
            glGetShaderInfoLog(shaderId,512,nullptr,log);
            printf("Error loading shader '%s' :\n%s\n",file.c_str(),log);
            delete[] log;
        }
    }
}

}
