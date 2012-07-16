#include "GL/glew.h"
#include "mehteor.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    Canvas canvas(640,480);
    
    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,

        0.5f,0.5f, 0.0f,
        -0.5f,-0.5f, 0.0f,
        0.5f,-0.5f, 0.0f
    };

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    /*
    float vertices2[] = {
        0.0f, 0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        -0.8f, -0.8f, 0.0f
    };
    */

    VertexAttributes vrtexAttributes;
    vrtexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    //vrtexAttributes.addAttribute(VertexAttribute(2,VertexAttributes::textureAttribute));
    Mesh mesh(vrtexAttributes);
    mesh.setVertices(6,3,vertices);

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

    Texture t;
    printf("Texture loaded: %i\n", t.load("res/test.png"));

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    mesh.bind(shaderProgram);
    mesh.render(shaderProgram);

    printf("%s\n",gluErrorString(glGetError()));
    canvas.flip();

    System::sleep(2000);

    System::deinit();
    return 0;
}
