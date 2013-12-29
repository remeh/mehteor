#ifndef MEH_ACTOR_H
#define MEH_ACTOR_H

#include "engine/renderer.h"

namespace meh {

/**
 * Basic definition of an Actor into a Scene.
 */
class Actor {
    private:
    protected:
    public:
        Actor() {};
        virtual ~Actor() {};

        virtual void draw(Renderer* renderer) = 0;
        virtual void update() = 0;
};

} // namespace meh

#endif // MEH_ACTOR_H
