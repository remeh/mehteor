#include "GL/glew.h"
#include "mehteor.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    Canvas canvas(640,480);
    
    float vertices[] = {
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    ByteBuffer buffer(50);
    printf("%c %c %c\n",buffer.readChar(),buffer.readChar(),buffer.readChar());
    buffer.reset();
    buffer.writeChar('a');
    buffer.writeChar('b');
    buffer.writeChar('c');
    char* a = "def";
    buffer.write(a,3);
    buffer.write("ghi",3);
    buffer.reset();
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    buffer.resize(3,true);
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    buffer.resize(3,false);
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());
    printf("%c\n",buffer.readChar());

    Texture t;
    printf("Texture loaded: %i\n", t.load("res/test.png"));
    

    /*
    float vertices2[] = {
        0.0f, 0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        -0.8f, -0.8f, 0.0f
    };
    */
    VBO vbo(3,2,vertices);

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

    printf("%s\n",gluErrorString(glGetError()));
    canvas.flip();

    System::sleep(2000);

    System::deinit();
    return 0;
}
