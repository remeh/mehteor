#ifndef MEH_RENDERER_H
#define MEH_RENDERER_H

#include "graphics/shaderprogram.h"

namespace meh {

class Sprite;

class Renderer {
    private:
    protected:
    public:
        Renderer() {};
        virtual ~Renderer() {};

        virtual void begin(ShaderProgram* shaderProgram) = 0;
        virtual void end() = 0;

        virtual void draw(Sprite& sprite) = 0;
};

} // namespace meh

#endif // MEH_RENDERER_H
