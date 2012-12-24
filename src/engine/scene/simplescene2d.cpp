#include "engine/scene/scene.h"
#include "engine/scene/simplescene2d.h"
#include "engine/scene/scenenode.h"
#include "engine/scene/actor.h"
#include "engine/scene/spriteactor.h"
#include "engine/camera/camera.h"
#include "engine/camera/orthographiccamera.h"

using namespace std;

namespace meh {

SimpleScene2D::SimpleScene2D(float width, float height) :
    cam(new OrthographicCamera(width,height)),
    // Default shader used to render the whole scene if none are defined
    // in the scenenode.
    vertexShader("res/shaders/vertex.glsl",Shader::ShaderType::VERTEX_SHADER),
    fragmentShader("res/shaders/fragment.glsl",Shader::ShaderType::FRAGMENT_SHADER) {

    // TODO this default node should be accessible
    SceneNode* node = new SceneNode(&vertexShader, &fragmentShader);
    nodes.push_back(node);

    // Using a ortho camera, we set 0,0 on the left bottom on the screen.
    cam->setPosition(320.0f,240.0f,0.0f);
    // Updates the model view projection
    cam->update();
    spriteRenderer.setModelViewMatrix(cam->modelViewProjection());
}

SimpleScene2D::~SimpleScene2D() {
    if (cam) {
        delete cam;
        cam = nullptr;
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete *it;
    }
}

void SimpleScene2D::update() {
    // As long as we don't change the viewport or the zoom factor,
    // we don't need to update the camera
    // but we must update every nodes
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        (*it)->update();
    }
}

void SimpleScene2D::render() {
    // renders each node of the scene
    if (nodes.size() == 0) {
        printf("WARNING: no node to render in this Scene2d[%p]", this);
        return;
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        (*it)->render(&spriteRenderer);
    }
}

void SimpleScene2D::addNode(SceneNode* node) {
    if (node != nullptr) {
        nodes.push_back(node);
    } else {
        printf("WARNING: tried to insert a null node in this Scene2d[%p].\n", this);
    }
}

Camera* SimpleScene2D::camera() {
    return cam;
}

} // namespace meh
