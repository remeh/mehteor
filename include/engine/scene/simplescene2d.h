#ifndef MEH_SIMPLESCENE2D_H
#define MEH_SIMPLESCENE2D_H

#include <deque>

#include "engine/scene/scene.h"
#include "engine/scene/actor.h"
#include "graphics/shader.h"
#include "graphics/shaderprogram.h"
#include "engine/camera/camera.h"
#include "engine/camera/orthographiccamera.h"
#include "engine/renderer.h"
#include "engine/spriterenderer.h"

using namespace std;

namespace meh {

class SimpleScene2D : public Scene {
    private:
        /**
         * Camera used to represent the scene.
         */
        OrthographicCamera* cam;

        /**
         * The renderer used to render Sprites.
         */
        SpriteRenderer spriteRenderer;

        /**
         * scene width
         */
        float w;
        /**
         * scene height
         */
        float h;

        Shader vertexShader;
        Shader fragmentShader;
        ShaderProgram shaderProgram;

        deque<Actor*> actors;

    protected:
    public:
        SimpleScene2D(float width, float height);
        ~SimpleScene2D();

        void update();
        void render();
        Camera* camera();

        /**
         * Adds an Actor in this Scene.
         * The memory is managed by the Scene.
         *
         * @param actor the Actor to add to the Scene.
         */
        void addActor(Actor* actor);

        /**
         * Removes an Actor from this Scene.
         * The memory of the returned pointer must be handled by the caller.
         *
         * @param actor the Actor to remove.
         * @return a pointer to the removed Actor.
         */
        Actor* removeActor(Actor* actor);

        Renderer& renderer() {
            return spriteRenderer;
        }
};

} // namespace meh

#endif // MEH_SIMPLESCENE2D_H
