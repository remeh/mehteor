#include "GL/glew.h"
#include "mehteor.h"

#include "core/quaternion.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();
    
    /*
     * Byte buffer
     *
     */
    ByteBuffer buffer(5);
    buffer.write("abc",3);
    buffer.reset();
    buffer.resize(3,true);
    printf("%c\n",buffer.readByte());
    printf("%c\n",buffer.readByte());
    printf("%c\n",buffer.readByte());
    buffer.reset();

    /*
     * Canvas
     */
    Canvas canvas(640,480);
    if (!canvas.surface()) {
        return -1;
    }

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

    ResourcesManager resourcesManager;
    resourcesManager.loadTexture("lama1","res/lama1.png");
    resourcesManager.loadTexture("lama2","res/lama2.png");
    resourcesManager.loadTexture("test","res/test.png");

    resourcesManager.getTexture("lama2")->bind(0);

    SpriteRenderer renderer(resourcesManager);
    
    Sprite sprite(*(resourcesManager.getTexture("lama2")));
    Sprite sprite2(*(resourcesManager.getTexture("lama1")));

    InputDevicesManager& idm = canvas.inputDevicesManager();

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

    renderer.draw(sprite,shaderProgram);
    canvas.flip();
    printf("%s\n",gluErrorString(glGetError()));
    System::sleep(1000);

    renderer.draw(sprite2,shaderProgram);
    canvas.flip();
    shaderProgram.disable();
    printf("%s\n",gluErrorString(glGetError()));
    System::sleep(1000);

    System::deinit();
    return 0;
}
