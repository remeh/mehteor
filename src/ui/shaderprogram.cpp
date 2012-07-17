#include <string>
#include <cstdio> // printf
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "ui/shaderprogram.h"
#include "ui/shader.h"

using namespace std;

namespace meh {

ShaderProgram::ShaderProgram() {
    shaderProgramId = glCreateProgram();
}

void ShaderProgram::addShader(Shader* shader) {
    shders.push_back(shader);
    glAttachShader(shaderProgramId, shader->id());
}

void ShaderProgram::link() {
    // XXX Ok as we only have one output right now
    // but should be more flexible
    glBindFragDataLocation(shaderProgramId, 0, "outColor");
    glLinkProgram(shaderProgramId);    
    // Check whether the link succeed
    GLint compileStatus;
    glGetProgramiv(shaderProgramId,GL_LINK_STATUS,&compileStatus);
    if (compileStatus != GL_TRUE) {
        // doesn't seem ok, display the log
        GLint length;
        glGetProgramiv(shaderProgramId, GL_INFO_LOG_LENGTH, &length);
        char* log = new char[length];
        glGetProgramInfoLog(shaderProgramId,length,nullptr,log);
        printf("Error linking shader :\n%s\n",log);
        delete[] log;
    }
}

void ShaderProgram::enable() {
    glUseProgram(shaderProgramId);
}

void ShaderProgram::disable() {
    glUseProgram(0);
}

void ShaderProgram::enableVertexAttribute(string name) {
    GLint idx = glGetAttribLocation(shaderProgramId, name.c_str());
    if (idx != -1) {
        glEnableVertexAttribArray(idx);
    }
}

void ShaderProgram::setVertexAttribute(string name, int dimension, int type, bool normalize) {
    GLint idx = glGetAttribLocation(shaderProgramId, name.c_str());
    if (idx != -1) {
        glVertexAttribPointer(idx,dimension,type,normalize,0,0);
    }
}

}

