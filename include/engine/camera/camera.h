#ifndef MEH_CAMERA_H
#define MEH_CAMERA_H

#include "core/vector3d.h"
#include "core/matrix4x4.h"

namespace meh {

/**
 * Default class for Camera.
 */
class Camera {
    private:
    protected:
        /**
         * Camera position.
         */
        Vector3d<float> pos;
        /**
         * Camera direction.
         */
        Vector3d<float> dir;
        /**
         * Camera up vector.
         */
        Vector3d<float> u;

        /**
         * Projection matrix.
         */
        Matrix4x4<float> projMatrix;

        /**
         * ModelView matrix.
         */
        Matrix4x4<float> viewMatrix;

        /**
         * Results of the combination of projection matrix and the modelview matrix.
         */
        Matrix4x4<float> resultMatrix;

        Matrix4x4<float> invResultMatrix;

        float viewportW;

        float viewportH;

        /**
         * Near clipping plane distance.
         */
        float nr;

        /**
         * Far clipping plane distance.
         */
        float fr; 

    public:
        Camera();
        virtual ~Camera();

        /**
         * Move the target of this Camera to the provided position.
         */
        void lookAt(float x, float y, float z);

        virtual void update() = 0;

        Matrix4x4<float>& modelViewProjection()
        {
            return resultMatrix;
        }

        Matrix4x4<float>& invertModelViewProjection() 
        {
            return invResultMatrix;
        }

        void setPosition(float x, float y, float z);

        void translate(Vector3d<float> translation);

        float near()
        {
            return nr;
        }

        float far()
        {
            return fr;
        }
};

} // namespace meh

#endif // MEH_CAMERA_H
