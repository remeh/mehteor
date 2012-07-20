#include "graphics/camera.h"

namespace meh {

Camera::Camera() :
    dir(0.0f,0.0f,-1.0f),
    u(0.0f,1.0f,0.0f),
    viewportW(0.0f),
    viewportH(0.0f),
    nr(1.0f),
    fr(100.0f) {
}

Camera::~Camera() {

}

void Camera::lookAt(float x, float y, float z) {
    dir.setXYZ(x,y,z);
    dir = dir - pos;
    dir.normalize();
}

void Camera::setPosition(float x, float y, float z) {
    pos.setXYZ(x,y,z);
}

}
