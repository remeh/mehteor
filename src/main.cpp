#include "core/system.h"
#include "ui/canvas.h"
#include "ui/shader.h"
#include "ui/shaderprogram.h"
#include "ui/vbo.h"
#include "GL/glew.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    Canvas canvas(640,480);
    
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    float vertices2[] = {
        0.0f, 0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        -0.8f, -0.8f, 0.0f
    };
    VBO vbo(3,3,vertices);
    VBO vbo2(3,3,vertices2);

    Shader vertex("res/shaders/vertex.glsl",Shader::ShaderType::VERTEX_SHADER);
    Shader fragment("res/shaders/fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER);
    Shader fragment2("res/shaders/fragment2.glsl",Shader::ShaderType::FRAGMENT_SHADER);

    ShaderProgram shaderProgram;
    shaderProgram.addShader(&vertex);
    shaderProgram.addShader(&fragment);
    shaderProgram.link();

    ShaderProgram shaderProgram2;
    shaderProgram2.addShader(&vertex);
    shaderProgram2.addShader(&fragment2);
    shaderProgram2.link();

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    shaderProgram.enable();
    vbo.bind(&shaderProgram);
    glDrawArrays(GL_TRIANGLES,0,3);
    vbo2.bind(&shaderProgram);
    glDrawArrays(GL_TRIANGLES,0,3);

    printf("%s\n",gluErrorString(glGetError()));
    canvas.flip();

    System::sleep(2000);

    System::deinit();
    return 0;
}
