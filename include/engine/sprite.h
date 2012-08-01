#ifndef MEH_SPRITE_H
#define MEH_SPRITE_H

#include "core/rect.h"
#include "graphics/texture.h"
#include "engine/spriterenderer.h"

namespace meh {

class Sprite {
    public: // static
        /**
         * The size of one vertex of this Sprite.
         */
        static int VERTEX_SIZE;
        /**
         * The number of vertices for one sprite
         */
        static int SIZE;

    private:
        Texture* tex;

        Rect<float> r;

        /**
         * Scale on x-axis.
         */
        float scleX;
        /**
         * Scale on y-axis.
         */
        float scleY;

        /**
         * Region to use in the Texture to represent this Sprite.
         */
        Rect<float> texRegion;

    protected:
    public:
        /**
         * Constructs a sprite based on a texture, with a size equals on the texture size, position at 0,0.
         */
        Sprite(Texture* texture);
        ~Sprite();

        void draw(SpriteRenderer spriteRenderer);

        Texture* texture() {
            return tex;
        }

        Rect<float>& rect() {
            return r;
        }

        float x() {
            return r.x();
        }

        float y() {
            return r.y();
        }

        float width() {
            return r.width();
        }

        float height() {
            return r.height();
        }

        Rect<float>& textureRegion() {
            return texRegion;
        }

        void setPosition(float x, float y);
};

} // namespace meh

#endif // MEH_SPRITE_H
