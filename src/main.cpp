#include "GL/glew.h"
#include "mehteor.h"

#include "core/quaternion.h"

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
    
    GLfloat vertices[] = {
        // Vertex          // Texcoord
        /*
        -310.0f,230.0f, 0.0f, 0.0f, 0.0f,
        310.0f,230.0f, 0.0f,   1.0f, 0.0f,
        310.0f,-230.0f, 0.0f,  1.0f, 1.0f,
        -310.0,-230.0f,0.0f,   0.0f, 1.0f
        */
        0.0f,0.0f, 0.0f, 0.0f, 0.0f,
        350.0f,0.0f,0.0f,   0.0f, 1.0f,
        350.0f,250.0f, 0.0f,  1.0f, 1.0f,
        0.0f,250.0f,0.0f,   1.0f, 0.0f
    };

    GLuint elements[] = {
        0, 1 ,2,
        2, 3, 0
    };

    VertexAttributes vrtexAttributes;
    vrtexAttributes.addAttribute(VertexAttribute(3,0,VertexAttributes::positionAttribute));
    vrtexAttributes.addAttribute(VertexAttribute(2,3,VertexAttributes::textureCoordinatesAttribute));
    Mesh mesh(vrtexAttributes);
    mesh.setVertices(4,6,vertices);
    mesh.setElements(2,3,elements);

    Shader vertex("res/shaders/vertex.glsl",Shader::ShaderType::VERTEX_SHADER);
    Shader fragment("res/shaders/fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER);

    ShaderProgram shaderProgram;
    shaderProgram.addShader(&vertex);
    shaderProgram.addShader(&fragment);
    shaderProgram.link();

    OrthographicCamera camera(640,480);

    shaderProgram.enable();

    /*
    int loc = glGetAttribLocation(shaderProgram.id(),"meh_modelViewMatrix");
    printf("loc: %i\n", loc);
    glEnableVertexAttribArray(loc);
    */

    Texture tex1;
    printf("Texture loaded: %i\n",tex1.load("res/test.png"));
    tex1.bind(0);
    Texture tex2;
    /*
    printf("Texture loaded: %i\n",tex2.load("res/lama1.png"));
    tex1.bind(0);
    shaderProgram.setUniformi("meh_texture",0);
    */

    mesh.bind(shaderProgram);
    mesh.render(shaderProgram);

    InputDevicesManager& idm = canvas.inputDevicesManager();

    float a = 0.0f;
    while (a < 20.0f) {
        canvas.clear(0.0f,0.0f,0.0f,1.0f);
        idm.update();
        printf("%i %i\n",idm.mouseX(),idm.mouseY());
        camera.setPosition(320.0f,240.0f,0.0f);
        camera.update();

        if (idm.keyPressed(SDLK_SPACE)) {
            printf("SPACE!\n");
        }

        if (idm.leftButton()) {
            printf("left button\n");
        }
        if (idm.middleButton()) {
            printf("middle button\n");
        }
        if (idm.rightButton()) {
            printf("right button\n");
        }

        shaderProgram.setUniformMatrix4x4("meh_modelViewMatrix", camera.modelViewProjection());
        mesh.render(shaderProgram);
        canvas.flip();
        a += 0.1f;
    }

    printf("%s\n",gluErrorString(glGetError()));

    System::deinit();
    return 0;
}
