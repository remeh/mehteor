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
    Shader vertexRadialBlur("res/shaders/radialblur_vertex.glsl",Shader::ShaderType::VERTEX_SHADER);
    Shader fragmentRadialBlur("res/shaders/radialblur_fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER);

    ShaderProgram shaderProgram;
    shaderProgram.addShader(&vertex);
    shaderProgram.addShader(&fragment);
    shaderProgram.link();
    ShaderProgram radialBlur;
    radialBlur.addShader(&vertexRadialBlur);
    radialBlur.addShader(&fragmentRadialBlur);
    radialBlur.link();

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
    
    Sprite sprite(resourcesManager.getTexture("lama2"));
    Sprite sprite2(resourcesManager.getTexture("lama1"));

    SimpleScene2D scene2D(640,480);
    
    scene2D.addActor(new SpriteActor(sprite2));
    scene2D.addActor(new SpriteActor(sprite));

    InputDevicesManager& idm = canvas.inputDevicesManager();

    canvas.clear(0.0f,0.0f,0.0f,1.0f);
    idm.update();
    printf("%i %i\n",idm.mouseX(),idm.mouseY());

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

    while (1) {
        scene2D.update();
        scene2D.render();
        canvas.flip();
        idm.update();
        if (idm.keyPressed(SDLK_ESCAPE)) {
            break;
        } else if (idm.keyPressed(SDLK_LEFT)) {
            sprite.setPosition(sprite.x()-5.0f, sprite.y());
        } else if (idm.keyPressed(SDLK_RIGHT)) {
            sprite.setPosition(sprite.x()+5.0f, sprite.y());
        } else if (idm.keyPressed(SDLK_DOWN)) {
            sprite.setPosition(sprite.x(), sprite.y()-5.0f);
        } else if (idm.keyPressed(SDLK_UP)) {
            sprite.setPosition(sprite.x(), sprite.y()+5.0f);
        }
        System::sleep(17);
    }

    System::deinit();
    return 0;
}
