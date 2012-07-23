#ifndef MEH_ORTHOGRAPHICCAMERA_H
#define MEH_ORTHOGRAPHICCAMERA_H

#include "graphics/camera.h"

namespace meh {

class OrthographicCamera : public Camera {
    private:
        float zoom;

    protected:
    public:
        OrthographicCamera(float viewportWidth, float viewportHeight);
        ~OrthographicCamera();

        void update();
};

} // namespace meh

#endif // MEH_ORTHOGRAPHICCAMERA_H
