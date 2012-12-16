#ifndef MEH_SIMPLESCENE2D_H
#define MEH_SIMPLESCENE2D_H

#include <deque>

#include "engine/scene/scene.h"
#include "engine/scene/scenenode.h"
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
        ShaderProgram defaultShaderProgram;

        deque<SceneNode*> nodes;

    protected:
    public:
        SimpleScene2D(float width, float height);
        ~SimpleScene2D();

        void update();
        void render();

        Camera* camera();

        Renderer& renderer() {
            return spriteRenderer;
        }

        Shader& getDefaultVertexShader() {
            return vertexShader;
        }

        Shader& getDefaultFragmentShader() {
            return fragmentShader;
        }

        // XXX adds an actor to the default node.
        void addActor(Actor* actor);

        void addNode(SceneNode* node);
};

} // namespace meh

#endif // MEH_SIMPLESCENE2D_H
