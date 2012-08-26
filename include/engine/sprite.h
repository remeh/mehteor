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
        /**
         * Textures.
         */
        Texture* tex;

        /**
         * Bounding box of this Sprite (position and size).
         */
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
         * Rotation angle.
         */
        float rot;

        /**
         * Center on X for rotation and scaling
         */
        Vector2d<float> rotCenter;

        /**
         * Region to use in the Texture to represent this Sprite.
         * The region is in the texture coordinates (not normalized).
         */
        Rect<float> texRegion;

        /**
         * Is this sprite visible ?
         */
        bool vsible;

    protected:
    public:
        /**
         * Constructs a sprite based on a texture, with a size equals to the texture size, texture coordinates equals to the full texture and position at 0,0.
         * @param texture the texture to use to render this Sprite
         */
        Sprite(Texture* texture);
        /**
         * Constructs a Sprite based on a texture, with a size equals to the texture size, texture coordinates equals to the full texture and position at [x,y].
         * @param texture the texture to use to render this Sprite
         * @param x position in screen coordinates on the x-axis.
         * @param y position in screen coordinates on the y-axis.
         */
        Sprite(Texture* texture, float x, float y);
        /**
         * Constructs a Sprite based on a texture, with a size equals to the width and height provided, texture coordinates equals to the full texture and position at [x,y].
         * @param texture the texture to use to render this Sprite
         * @param x position in screen coordinates on the x-axis.
         * @param y position in screen coordinates on the y-axis.
         * @param width width on this sprite in screen coordinates.
         * @param height height on this sprite in screen coordinates.
         */
        Sprite(Texture* texture, float x, float y, float width, float height);
        /**
         * Constructs a Sprite based on a texture, with a size equals to the width and height provided, texture coordinates equals to the textureRegion provided and position at [x,y].
         * @param texture the texture to use to render this Sprite
         * @param x position in screen coordinates on the x-axis.
         * @param y position in screen coordinates on the y-axis.
         * @param width width on this sprite in screen coordinates.
         * @param height height on this sprite in screen coordinates.
         * @param textureRegion the region of the texture to use (in texture coordinates, not normalized).
         */
        Sprite(Texture* texture, float x, float y, float width, float height, Rect<float> textureRegion);

        ~Sprite();

        Texture* texture() {
            return tex;
        }

        /**
         * Returns the rectangle of this Sprites in the screen coordinates (position and size).
         *
         * @return the rectangle of this Sprites in the screen coordinates (position and size). 
         */
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

        /**
         * Returns the region of the texture used to render the Sprite.
         * This region is in the texture coordinates (not normalized).
         *
         * @return the region of the texture used to render the Sprite. 
         */
        Rect<float>& textureRegion() {
            return texRegion;
        }

        /**
         * Returns the scale on this Sprite on the x-axis. Default to 1.0f.
         * @return the scale on this Sprite on the x-axis. Default to 1.0f. 
         */
        float scaleX() {
            return scleX;
        }

        /**
         * Returns the scale on this Sprite on the y-axis. Default to 1.0f.
         * @return the scale on this Sprite on the y-axis. Default to 1.0f. 
         */
        float scaleY() {
            return scleY;
        }

        /**
         * Returns the rotation applied to this Sprite. Default at 0.0f. (used the rotation center as center)
         * @return the rotation applied to this Sprite. Default at 0.0f. (used the rotation center as center) 
         */
        float rotation() {
            return rot;
        }

        /**
         * Returns the center of the Sprite used for rotation and scaling.
         * @return the center of the Sprite used for rotation and scaling. 
         */
        Vector2d<float> rotationCenter() {
            return rotCenter;
        }

        /**
         * Sets this Sprite position in the screen coordinates.
         * @param x position on the x-axis.
         * @param y position on the y-axis.
         */
        void setPosition(float x, float y);

        /**
         * Sets around which point the rotation and the scaling is computed.
         * @param x center on the x-axis
         * @param y center on the y-axis
         */
        void setRotationCenter(float x, float y) {
            rotCenter.setXY(x,y);
        }

        /**
         * Sets this Sprite size in the screen coordinates.
         *
         * @param width size on the x-axis.
         * @param height size on the y-axis.
         */
        void setSize(float width, float height);

        /**
         * Sets this Sprite visible.
         */
        void show() {
            vsible = true;
        }

        /**
         * Hides this Sprite.
         */
        void hide() {
            vsible = false;
        }

        /**
         * Returns whether this Sprite is visible.
         */
        bool visible() {
            return vsible;
        }
};

} // namespace meh

#endif // MEH_SPRITE_H
