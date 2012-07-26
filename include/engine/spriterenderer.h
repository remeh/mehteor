#ifndef MEH_SPRITERENDERER_H
#define MEH_SPRITERENDERER_H

#include "core/rect.h"
#include "graphics/mesh.h"
#include "graphics/texture.h"
#include "graphics/shaderprogram.h"
#include "engine/resourcesmanager.h"

namespace meh {

class Sprite;

class SpriteRenderer {
    private:
        Mesh* msh;
        ResourcesManager& rsourcesManager;
        Texture* lastUsedTexture;

        void render();

    protected:
    public:
        SpriteRenderer(ResourcesManager& resourcesManager);
        ~SpriteRenderer();

        /**
         * XXX for the moment, directly renders a sprite using the provided shader program.
         */
        void draw(Sprite& sprite, ShaderProgram& shaderProgram);
};

} // namespace meh

#endif // MEH_SPRITERENDERER_H
