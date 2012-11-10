#include "engine/scene/scenenode.h"

namespace meh {

SceneNode::SceneNode(Shader* vertexShader, Shader* fragmentShader) :
    vertexShader(nullptr),
    fragmentShader(nullptr),
    shderProgram(nullptr) {
    setShaders(vertexShader, fragmentShader);
    defaultShaders = true;
    actors.clear();
}

SceneNode::~SceneNode() {
    deleteShaders();

    for (auto actor = actors.begin(); actor != actors.end(); actor++) {
        delete *actor;
    }
}

void SceneNode::addActor(Actor* actor) {
    if (actor != nullptr) {
        actors.push_back(actor);
    }
}

Actor* SceneNode::removeActor(Actor* actor) {
    // TODO
    return nullptr;
}

void SceneNode::deleteShaders() {
    if (!defaultShaders) {
        if (vertexShader) {
            delete vertexShader;
        }
        if (fragmentShader) {
            delete fragmentShader;
        }
    }
    if (shderProgram) {
        delete shderProgram;
    }
}

void SceneNode::render(SpriteRenderer* spriteRenderer) {
    if (!spriteRenderer) {
        printf("ERR: call to a SceneNode::render with a null renderer.\n");
        return;
    }
    if (shderProgram) {
        spriteRenderer->begin(shderProgram);
        for (auto it = actors.begin(); it != actors.end(); it++) {
            Actor* actor = *it;
            actor->draw(spriteRenderer);
        }
        spriteRenderer->end();
    }
}

void SceneNode::setShaders(Shader* vertexShader, Shader* fragmentShader) {
    deleteShaders();

    this->vertexShader = vertexShader;
    this->fragmentShader = fragmentShader;

    shderProgram = new ShaderProgram();
    shderProgram->addShader(vertexShader);
    shderProgram->addShader(fragmentShader);
    shderProgram->link();

    defaultShaders = false;
}

}

