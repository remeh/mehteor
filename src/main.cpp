#include "GL/glew.h"
#include "mehteor.h"


using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    Canvas canvas(640,480);
    
    float vertices[] = {
        // Vertex          // Texcoord
        -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
        0.5f,0.5f, 0.0f,   1.0f, 0.0f,
        0.5f,-0.5f, 0.0f,  1.0f, 1.0f,
        -0.5,-0.5f,0.0f,   0.0f, 1.0f
    };

    GLuint elements[] = {
        0, 1 ,2,
        2, 3, 0
    };


    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    Matrix4x4<float> a;
    a = a.mul(a);
    a = a.invert();

    VertexAttributes vrtexAttributes;
    vrtexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vrtexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    Mesh mesh(vrtexAttributes);
    mesh.setVertices(4,5,vertices);
    mesh.setElements(2,3,elements);

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

    glClearColor( 0.0f, 0.1f, 0.0f, 0.5f );
    glClear( GL_COLOR_BUFFER_BIT );

    shaderProgram.enable();

    Texture tex1;
    printf("Texture loaded: %i\n", tex1.load("res/test.png"));
    tex1.bind(0);

    shaderProgram.setUniformi("meh_texture",0);

    /*
    GLint s_textureId2 = glGetUniformLocation(shaderProgram.id(), "tex");
    lama2.bind(1);
    glUniform1i(s_textureId2, 1);
    */

    mesh.bind(shaderProgram);
    mesh.render(shaderProgram);
    mesh.unbind();
    glUseProgram(0);
    canvas.flip();

    System::sleep(1000);

    printf("%s\n",gluErrorString(glGetError()));

    System::deinit();
    return 0;
}
