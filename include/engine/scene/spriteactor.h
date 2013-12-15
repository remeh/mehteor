#ifndef MEH_SPRITEACTOR_H
#define MEH_SPRITEACTOR_H

#include "engine/scene/actor.h"

namespace meh {

class SpriteActor : public Actor {
    private:
        Sprite& s;

    protected:
    public:
        SpriteActor(Sprite& sprite);
        ~SpriteActor();

        void draw(Renderer* renderer);
        void update();

        Sprite& getSprite()
        {
            return s;
        }
};

} // namespace meh

#endif // MEH_SPRITEACTOR_H
