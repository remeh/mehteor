#include <cmath>
#include "graphics/orthographiccamera.h"

namespace meh {

OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight) :
    zoom(1.0f) {
    viewportW = viewportWidth;
    viewportH = viewportHeight;
}

OrthographicCamera::~OrthographicCamera() {

}

void OrthographicCamera::update() {
    projMatrix.toOrtho(zoom*(-viewportW)/2, zoom*viewportW/2, zoom*(-viewportH)/2, zoom*viewportH/2, fabs(near()), fabs(far()));
    Vector3d<float> tmp(pos.x(), pos.y(), pos.z());
    tmp = tmp + dir;
    viewMatrix.lookAt(pos, tmp, u);
    resultMatrix = projMatrix * viewMatrix;
    invResultMatrix = resultMatrix;
    invResultMatrix.invert();
}

}
