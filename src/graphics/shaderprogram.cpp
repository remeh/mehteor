#include <string>
#include <cstdio> // printf
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "graphics/shaderprogram.h"
#include "graphics/shader.h"
#include "core/matrix4x4.h"

using namespace std;

namespace meh {

string ShaderProgram::modelViewProjectionAttribute = "meh_modelViewMatrix";

ShaderProgram::ShaderProgram() {
    shaderProgramId = glCreateProgram();
}

void ShaderProgram::addShader(Shader* shader) {
    shders.push_back(shader);
    glAttachShader(shaderProgramId, shader->id());
}

void ShaderProgram::link() {
    //glBindFragDataLocation(shaderProgramId, 0, "outColor");
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

void ShaderProgram::setVertexAttribute(string name, int dimension, int offset, int dimVertex, int type, bool normalize) {
    GLint idx = glGetAttribLocation(shaderProgramId, name.c_str());
    if (idx != -1) {
        glVertexAttribPointer(idx, dimension, type, normalize, dimVertex*sizeof(GLfloat), (GLvoid*)(offset*sizeof(GLfloat)));
    }
}

int ShaderProgram::fetchUniformLocation(string name) {
    return glGetUniformLocation(shaderProgramId, name.c_str());
}

void ShaderProgram::setUniformi(string name, int value) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1i(position, value);
    }
}

void ShaderProgram::setUniformi(string name, int value, int value2) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform2i(position, value, value2);
    }
}

void ShaderProgram::setUniformi(string name, int value, int value2, int value3) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform3i(position, value, value2, value3);
    }
}

void ShaderProgram::setUniformi(string name, int value, int value2, int value3, int value4) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform4i(position, value, value2, value3, value4);
    }
}

void ShaderProgram::setUniformf(string name, float value) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1f(position, value);
    }
}

void ShaderProgram::setUniformf(string name, float value, float value2) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform2f(position, value, value2);
    }
}

void ShaderProgram::setUniformf(string name, float value, float value2, float value3) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform3f(position, value, value2, value3);
    }
}

void ShaderProgram::setUniformf(string name, float value, float value2, float value3, float value4) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform4f(position, value, value2, value3, value4);
    }
}

void ShaderProgram::setUniform1iv(string name, int count, int* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1iv(position, count, values);
    }
}

void ShaderProgram::setUniform2iv(string name, int count, int* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1iv(position, count/2, values);
    }
}

void ShaderProgram::setUniform3iv(string name, int count, int* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1iv(position, count/3, values);
    }
}

void ShaderProgram::setUniform4iv(string name, int count, int* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1iv(position, count/4, values);
    }
}

void ShaderProgram::setUniform1fv(string name, int count, float* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1fv(position, count, values);
    }
}

void ShaderProgram::setUniform2fv(string name, int count, float* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1fv(position, count/2, values);
    }
}

void ShaderProgram::setUniform3fv(string name, int count, float* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1fv(position, count/3, values);
    }
}

void ShaderProgram::setUniform4fv(string name, int count, float* values) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniform1fv(position, count/4, values);
    }
}

void ShaderProgram::setUniformMatrix4x4(string name, Matrix4x4<float>& matrix, bool transpose) {
    int position = fetchUniformLocation(name);
    if (position >= 0) {
        glUniformMatrix4fv(position,1,transpose,matrix.values());
    }
}

}

