#include "mehteor.h"

using namespace meh;

int main(int argc, char* argv[]) {
    System::init();
    
    /*
     * Byte buffer
     *
     */
    ByteBuffer buffer(5);
    char abc[4] = "abc";
    buffer.write(abc,3);
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

    Shader vertexRadialBlur("res/shaders/radialblur_vertex.glsl",Shader::ShaderType::VERTEX_SHADER);
    Shader fragmentRadialBlur("res/shaders/radialblur_fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER);
    ShaderProgram radialBlur;
    radialBlur.addShader(&vertexRadialBlur);
    radialBlur.addShader(&fragmentRadialBlur);
    radialBlur.link();

    ResourcesManager resourcesManager;
    resourcesManager.loadTexture("lama1","res/lama1.png");
    resourcesManager.loadTexture("spritesheet","res/ch.png");
    
    Sprite sprite2(resourcesManager.getTexture("lama1"));

    Rect<float> texCoords[] = { Rect<float>(32,0,32,32), Rect<float>(0,0,32,32), Rect<float>(32,0,32,32), Rect<float>(64,0,32,32)};
    unsigned int durations[] = { 100, 100, 100, 100 };
    Sprite sprite(resourcesManager.getTexture("spritesheet"));
    sprite.addAnimation("down", 4, durations, texCoords);
    sprite.setSize(128,128);
    sprite.setAnimation("down");

    SimpleScene2D scene2D(640,480);

    SceneNode* node = new SceneNode(&vertex,&fragment);
    scene2D.addNode(node);

    /*
    for (int i = 0; i < 1; i++) {
        SpriteActor* s = new SpriteActor(sprite2);
        if (s) {
            scene2D.addActor(s);
        }
    }
    */
    node->addActor(new SpriteActor(sprite));
    /*
    for (int i = 0; i < 141; i++) {
        SpriteActor* s = new SpriteActor(sprite2);
        if (s) {
            scene2D.addActor(s);
        }
    }
    */

    InputDevicesManager& idm = canvas.inputDevicesManager();

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

    long t = System::currentTime()+1000;
    float nbFrame = 0.0f;

    scene2D.update();
    printf("scene 2D updated\n");
    char title[10];

    Sound snd("res/music.ogg");
    Sound snd2("res/boump.ogg");
    AudioSystem system;
    system.play(&snd,true);

    while (1) {
        canvas.clear(0.0f,0.0f,0.0f,1.0f);
        scene2D.update();
        scene2D.render();
        canvas.flip();
        idm.update();
        if (idm.leftButton()) {
            printf("left button\n");
        }
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
        } else if (idm.keyPressed(SDLK_SPACE)) {
            system.play(&snd2,false);
        }
        nbFrame = nbFrame + 1.0f;
        if (t < System::currentTime()) {
            sprintf(title,"%.2f fps",nbFrame);
            canvas.setTitle(title);

            printf("%s\n",gluErrorString(glGetError()));
            nbFrame = 0.0f;
            t = System::currentTime()+1000;
        }
        System::sleep(16);
    }
    
    System::deinit();
    return 0;
}
