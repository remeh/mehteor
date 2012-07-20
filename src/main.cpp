#include "GL/glew.h"
#include "mehteor.h"


using namespace meh;

int main(int argc, char* argv[]) {
    System::init();

    ByteBuffer buffer(5);
    buffer.write("abc",3);
    buffer.reset();
    buffer.resize(3,true);
    printf("%c\n",buffer.readByte());
    printf("%c\n",buffer.readByte());
    printf("%c\n",buffer.readByte());
    buffer.reset();

    Canvas canvas(640,480);
    if (!canvas.surface()) {
        return -1;
    }
    
    /*
    float vertices[] = {
        // Vertex          // Texcoord
        -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
        0.5f,0.5f, 0.0f,   1.0f, 0.0f,
        0.5f,-0.5f, 0.0f,  1.0f, 1.0f,
        -0.5,-0.5f,0.0f,   0.0f, 1.0f
    };
    */
    float vertices[] = {
        // Vertex          // Texcoord
        100.0f,100.0f, 0.0f, 0.0f, 0.0f,
        100.0f,150.0f, 0.0f,   1.0f, 0.0f,
        150.0f,150.0f, 0.0f,  1.0f, 1.0f,
        150.0f,100.0f,0.0f,   0.0f, 1.0f
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
    a = a*a;
    a = a.invert();

    VertexAttributes vrtexAttributes;
    vrtexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vrtexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    Mesh mesh(vrtexAttributes);
    mesh.setVertices(4,5,vertices);
    mesh.setElements(2,3,elements);

    Shader vertex("res/shaders/vertex.glsl",Shader::ShaderType::VERTEX_SHADER);
    Shader fragment("res/shaders/fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER);

    ShaderProgram shaderProgram;
    shaderProgram.addShader(&vertex);
    shaderProgram.addShader(&fragment);
    shaderProgram.link();

    glClearColor( 0.0f, 0.1f, 0.0f, 0.5f );
    glClear( GL_COLOR_BUFFER_BIT );

    glFrustum(0, 640,480, 0, 1,2);

    shaderProgram.enable();

    OrthographicCamera camera(640,480);
    camera.setPosition(320,240,0);
    camera.update();
    shaderProgram.setUniformMatrix4x4("meh_modelViewProjection", camera.invertModelViewProjection());
    camera.modelViewProjection().print();

    Texture tex1;
    printf("Texture loaded: %i\n",tex1.load("res/lum.png"));
    tex1.bind(0);
    shaderProgram.setUniformi("meh_texture",0);

    mesh.bind(shaderProgram);
    mesh.render(shaderProgram);
    mesh.unbind();
    glUseProgram(0);
    canvas.flip();

    InputDevicesManager& idm = canvas.inputDevicesManager();
    idm.update();
    printf("%i %i\n",idm.mouseX(),idm.mouseY());

    System::sleep(2000);
    idm.update();
    printf("%i %i\n",idm.mouseX(),idm.mouseY());

    printf("%s\n",gluErrorString(glGetError()));

    System::deinit();
    return 0;
}
