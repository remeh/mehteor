#include "engine/scene/scene.h"
#include "engine/scene/simplescene2d.h"
#include "engine/scene/actor.h"
#include "engine/scene/spriteactor.h"
#include "engine/camera/camera.h"
#include "engine/camera/orthographiccamera.h"

using namespace std;

namespace meh {

SimpleScene2D::SimpleScene2D(float width, float height) :
    cam(new OrthographicCamera(width,height)),

    // Shader used to render the whole scene
    // TODO an amelioration would be to be able to specify which
    // TODO shader to use for which node of actors.
    vertexShader("res/shaders/vertex.glsl",Shader::ShaderType::VERTEX_SHADER),
    fragmentShader("res/shaders/fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER) {
    shaderProgram.addShader(&vertexShader);
    shaderProgram.addShader(&fragmentShader);
    shaderProgram.link();

    // Sets 0,0 on the left bottom on the screen.
    cam->setPosition(320.0f,240.0f,0.0f);
    // Updates the model view projection
    cam->update();
    spriteRenderer.setModelViewMatrix(cam->modelViewProjection());

    actors.clear();
}

SimpleScene2D::~SimpleScene2D() {
    if (cam) {
        delete cam;
        cam = nullptr;
    }
    for (auto actor = actors.begin(); actor != actors.end(); actor++) {
        delete *actor;
    }
    actors.clear();
}

void SimpleScene2D::update() {
    // As long as we don't change the viewport or the zoom factor,
    // we don't need to update the camera
}

void SimpleScene2D::render() {
    spriteRenderer.begin(&shaderProgram);
    for (auto it = actors.begin(); it != actors.end(); it++) {
        Actor* actor = *it;
        actor->draw(&spriteRenderer);
    }
    spriteRenderer.end();
}

Camera* SimpleScene2D::camera() {
    return cam;
}

void SimpleScene2D::addActor(Actor* actor) {
    if (actor != nullptr) {
        actors.push_back(actor);
    }
}

Actor* SimpleScene2D::removeActor(Actor* actor) {
    // TODO
    return nullptr;
}

} // namespace meh