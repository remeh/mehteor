#ifndef MEH_ORTHOGRAPHICCAMERA_H
#define MEH_ORTHOGRAPHICCAMERA_H

#include "engine/camera/camera.h"

namespace meh {

class OrthographicCamera : public Camera {
    private:
        float zoom;

        /**
         * Tracks whether a variable of this Camera has changed, if not we
         * don't need to recompute everything.
         */
        bool dirty;

    protected:
    public:
        OrthographicCamera(float viewportWidth, float viewportHeight);
        ~OrthographicCamera();

        void update();

        /**
         * Sets a zoom applied to this Camera.
         * @param value the zoom to apply to this Camera.
         */
        void setZoom(float value);
};

} // namespace meh

#endif // MEH_ORTHOGRAPHICCAMERA_H
