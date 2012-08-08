#ifndef MEH_SPRITERENDERER_H
#define MEH_SPRITERENDERER_H

#include "core/rect.h"
#include "graphics/mesh.h"
#include "graphics/texture.h"
#include "graphics/shaderprogram.h"
#include "engine/renderer.h"

namespace meh {

class Sprite;

class SpriteRenderer : public Renderer {
    private:
        Mesh* msh;
        Texture* lastUsedTexture;
        
        /**
         * How many Sprite this Renderer could buffer.
         */
        unsigned int sze;
        GLfloat* vrtices;
        GLuint* elmts;
        int idx;

        /**
         * To know how many sprites are currently in the buffer, because
         * the buffer has a limited sized. Used to flush the buffer
         * when needed.
         */
        unsigned int spriteBuffered;

        ShaderProgram* shaderProgram;

        Matrix4x4<float> mdelViewMatrix;

        /**
         * Used when we need to compute the texture coordinates
         * between [0.0f;1.0f] using the coordinates in the
         * texture coordinates
         */
        float invTexW;
        /**
         * Used when we need to compute the texture coordinates
         * between [0.0f;1.0f] using the coordinates in the
         * texture coordinates
         */
        float invTexH;

        /**
         * True when the SpriteRenderer is rendering (between the call of begin() and end()).
         */
        bool isRendering;
        
        void render();

        /**
         * Switch the currently used texture.
         * Can render the vertices which were already set and computes
         * the new inverse texture coordinates. Doesn't do anything
         * if we don't need to switch the texture.
         * @param newTexture the new texture to switch to.
         */
        void switchTexture(Texture* newTexture);

    protected:
    public:
        SpriteRenderer();
        /**
         * @param size number of Sprite this renderer should bufferize.
         */
        SpriteRenderer(unsigned int size);
        ~SpriteRenderer();

        void init();
        /**
         * TODO comment
         * @param deleteMesh whether the internally used Mesh should be deleted.
         */
        void deinit(bool deleteMesh = true);

        void draw(Sprite& sprite);
        
        /**
         * TODO comment
         * @param texture the texture to use for the drawing
         * @param x the coordinate on the x-axis
         * @param y the coordinate on the y-axis
         * @param w the width
         * @param h the height
         * @param centerX the scaling and rotation center for the x-axis
         * @param centerY the scaling and rotation center for the y-axis
         * @param scaleX the scale on the x-axis
         * @param scaleY the scale on the y-axis
         * @param rotation the rotation to apply (with center centerX/centerY)
         * @param texX the coordinate on the x-axis in the texture coordinates (not normalized)
         * @param texY the coordinate on the y-axis in the texture coordinates (not normalized)
         * @param texW the width on the x-axis in the texture coordinates (not normalized)
         * @param texH the height on the y-axis in the texture coordinates (not normalized)
         * @param flipX whether the texture should be flipped horizontally
         * @param flipY whether the texture should be flipped vertically
         */
        void draw(Texture* texture, float x, float y, float w, float h, float centerX, float centerY,
                float scaleX, float scaleY, float rotation, float texX, float texY, float texW, float texH,
                bool flipX, bool flipY);

        void begin(ShaderProgram* shaderProgram);
        void end();

        void setModelViewMatrix(Matrix4x4<float>& modelViewMatrix) {
            mdelViewMatrix.set(modelViewMatrix);
        }
};

} // namespace meh

#endif // MEH_SPRITERENDERER_H
