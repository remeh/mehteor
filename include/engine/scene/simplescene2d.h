#ifndef MEH_SIMPLESCENE2D_H
#define MEH_SIMPLESCENE2D_H

#include <deque>
#include <memory>

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
        unique_ptr<OrthographicCamera> cam;

        /**
         * The renderer used to render Sprites.
         */
        SpriteRenderer spriteRenderer;

        Shader vertexShader;
        Shader fragmentShader;
        ShaderProgram defaultShaderProgram;

        deque< shared_ptr<SceneNode> > nodes;

    protected:
    public:
        SimpleScene2D(float width, float height);
        ~SimpleScene2D();

        void update();
        void render();

        const Camera* getCamera();

        Renderer& renderer()
        {
            return spriteRenderer;
        }

        Shader& getDefaultVertexShader()
        {
            return vertexShader;
        }

        Shader& getDefaultFragmentShader()
        {
            return fragmentShader;
        }

        /**
         * Adds a node to this scene2D.
         *
         * @param node      the node to add.
         */
        void addNode(shared_ptr<SceneNode> node);
};

} // namespace meh

#endif // MEH_SIMPLESCENE2D_H
