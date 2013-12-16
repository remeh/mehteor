#ifndef MEH_SPRITE_H
#define MEH_SPRITE_H

#include <map>
#include <string>

#include "core/rect.h"
#include "core/vector4d.h"
#include "graphics/texture.h"
#include "engine/spriterenderer.h"
#include "engine/spriteanimation.h"

using namespace std;

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
        /**
         * The name of the default animation.
         */
        static string DEFAULT_ANIMATION;

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
         * Tint color.
         */
        Vector4d<float> tint;

        /**
         * Center on X for rotation and scaling
         */
        Vector2d<float> rotCenter;

        map<string, SpriteAnimation*> anims;

        /**
         * Region to use in the Texture to represent this Sprite.
         * The region is in the texture coordinates (not normalized).
         */
        Rect<float> texRegion;

        /**
         * Is this sprite visible ?
         */
        bool vsible;

        /**
         * Pointer on the current animation. Do not delete memory of this pointer.
         */
        SpriteAnimation* currAnimation;

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

        void addAnimation(string name, int nbFrames, const unsigned int* durations, const Rect<float>* texCoords);

        Texture* texture() {
            return tex;
        }

        /**
         * Returns the rectangle of this Sprites in the screen coordinates (position and size).
         *
         * @return the rectangle of this Sprites in the screen coordinates (position and size). 
         */
        Rect<float>& getRect() {
            return r;
        }

        float getX() {
            return r.x();
        }

        float getY() {
            return r.y();
        }

        float getWidth() {
            return r.width();
        }

        float getHeight() {
            return r.height();
        }

        /**
         * Returns the region of the texture used to render the Sprite.
         * This region is in the texture coordinates (not normalized).
         *
         * @return the region of the texture used to render the Sprite. 
         */
        Rect<float>& getTextureRegion();

        /**
         * Returns a reference to the current SpriteAnimation.
         * @return a reference to the current SpriteAnimation. 
         */
        SpriteAnimation& currentAnimation();

        /**
         * Sets the current animation of this sprite.
         * @param name the name of the animation to set.
         * @return true if the animation exists and everything went fine.
         */
        bool setAnimation(string name);

        /**
         * Returns the scale on this Sprite on the x-axis. Default to 1.0f.
         * @return the scale on this Sprite on the x-axis. Default to 1.0f. 
         */
        float getScaleX()
        {
            return scleX;
        }

        /**
         * Returns the scale on this Sprite on the y-axis. Default to 1.0f.
         * @return the scale on this Sprite on the y-axis. Default to 1.0f. 
         */
        float getScaleY()
        {
            return scleY;
        }

        /**
         * Returns the rotation applied to this Sprite. Default at 0.0f. (used the rotation center as center)
         * @return the rotation applied to this Sprite. Default at 0.0f. (used the rotation center as center) 
         */
        float getRotation()
        {
            return rot;
        }

        Vector4d<float> getTint()
        {
            return tint;
        }

        /**
         * Returns the center of the Sprite used for rotation and scaling.
         * @return the center of the Sprite used for rotation and scaling. 
         */
        Vector2d<float> getRotationCenter() {
            return rotCenter;
        }

        /**
         * Sets this Sprite position in the screen coordinates.
         * @param x position on the x-axis.
         * @param y position on the y-axis.
         */
        void setPosition(float x, float y);

        /**
         * Sets the rotation angle.
         * @param rot       the rotation
         */
        void setRotation(int rot)
        {
            this->rot = rot;
        }

        void setTint(float r, float g, float b, float a)
        {
            tint.setXYZI(r,g,b,a);
        }
        
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

        /**
         * Update the sprites (for animations).
         */
        void update();
};

} // namespace meh

#endif // MEH_SPRITE_H
