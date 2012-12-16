#ifndef MEH_SCENENODE_H
#define MEH_SCENENODE_H

#include <deque>

#include "engine/scene/scene.h"
#include "engine/scene/actor.h"
#include "graphics/shader.h"
#include "graphics/shaderprogram.h"
#include "engine/renderer.h"
#include "engine/spriterenderer.h"

using namespace std;

namespace meh
{

class SceneNode
{
    private:
        deque<Actor*> actors;

        Shader* vertexShader;
        Shader* fragmentShader;
        ShaderProgram* shderProgram;

        bool defaultShaders;

        void deleteShaders();


    protected:
    public:
        SceneNode(Shader* vertexShader, Shader* fragmentShader);
        ~SceneNode();

        void render(SpriteRenderer* renderer);
        
        /**
         * Adds an Actor in this SceneNode.
         * The memory is managed by the SceneNode.
         *
         * @param actor the Actor to add to the Scene.
         */
        void addActor(Actor* actor);

        /**
         * Removes an Actor from this SceneNode.
         * The memory of the returned pointer must be handled by the caller.
         *
         * @param actor the Actor to remove.
         * @return a pointer to the removed Actor.
         */
        Actor* removeActor(Actor* actor);

        /**
         * Delete very Actors of this SceneNode.
         */
        void deleteActors();

        void setShaders(Shader* vertexShader, Shader* fragmentShader);

        ShaderProgram* shaderProgram() {
            return shderProgram;
        }
};

}

#endif // MEH_SCENENODE_H

