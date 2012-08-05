#ifndef MEH_SCENE_H
#define MEH_SCENE_H

#include "engine/camera/camera.h"

namespace meh {

/**
 * Basic definition of a Scene.
 */
class Scene {
    private:
    protected:
    public:
        Scene() {};
        virtual ~Scene() {};

        virtual void update() = 0;
        virtual void render() = 0;
        virtual Camera* camera() = 0;
};

} // namespace meh

#endif // MEH_SCENE_H
