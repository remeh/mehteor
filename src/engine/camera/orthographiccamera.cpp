#include <cmath>
#include "engine/camera/orthographiccamera.h"

namespace meh {

OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight) :
    zoom(1.0f) {
    viewportW = viewportWidth;
    viewportH = viewportHeight;
    nr = 0.0f;

    dirty = true;
}

OrthographicCamera::~OrthographicCamera() {

}

void OrthographicCamera::update() {
    if (dirty) {
        projMatrix.toOrtho(zoom*(-viewportW)/2, zoom*viewportW/2, zoom*(-viewportH)/2, zoom*viewportH/2, fabs(near()), fabs(far()));
        
        viewMatrix.lookAt(pos, pos+dir, u);

        resultMatrix = projMatrix * viewMatrix;

        invResultMatrix = resultMatrix;
        invResultMatrix.invert();

        dirty = false;
    }
}

void OrthographicCamera::setZoom(float value) {
    zoom = value;
    dirty = true;
}

}
