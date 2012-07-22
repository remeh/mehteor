#include <cmath>
#include "graphics/orthographiccamera.h"

namespace meh {

OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight) :
    zoom(1.0f) {
    viewportW = viewportWidth;
    viewportH = viewportHeight;
    nr = 0.0f;
}

OrthographicCamera::~OrthographicCamera() {

}

void OrthographicCamera::update() {
    projMatrix.toOrtho(zoom*(-viewportW)/2, zoom*viewportW/2, zoom*(-viewportH)/2, zoom*viewportH/2, fabs(near()), fabs(far()));
    
    viewMatrix.lookAt(pos, pos+dir, u);

    printf("View matrix\n");
    viewMatrix.print();

    resultMatrix = projMatrix * viewMatrix;

    printf("Viewport: %f %f \n",viewportW, viewportH);

    // Result Matrix
    printf("Result Matrix : \n");
    resultMatrix.print();

    invResultMatrix = resultMatrix;
    invResultMatrix.invert();

    printf("Inv Result Matrix : \n");
    invResultMatrix.print();
}

}
