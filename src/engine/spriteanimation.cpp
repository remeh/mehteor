#include <iostream>
#include "engine/spriteanimation.h"
#include "core/system.h"

namespace meh {

SpriteAnimation::SpriteAnimation(string name, unsigned int nbFrames, const unsigned int* durations, const Rect<float>* texCoords) :
    nFrames(nbFrames),
    currFrame(0),
    n(name) {
    this->texCoords = new Rect<float>[nFrames];
    for (unsigned int i = 0; i < nFrames; i++) {
        this->texCoords[i] = texCoords[i];
    }

    this->durations = new unsigned int[nFrames];
    for (unsigned int i = 0; i < nFrames; i++) {
        this->durations[i] = durations[i];
    }
    
    nextFrame = 0.0;
}

SpriteAnimation::~SpriteAnimation() {
    if (texCoords)
        delete[] texCoords;
    if (durations)
        delete[] durations;
}

bool SpriteAnimation::tick() {
    double currTime = System::currentTime();
    if (currTime > nextFrame) {
        currFrame++;
        if (currFrame == nFrames) {
            currFrame = 0;
        }
        nextFrame = currTime + (static_cast<double>(durations[currFrame]));
        return true;
    }
    return false;
}

void SpriteAnimation::setCurrentFrame(unsigned int currFrame) {
    this->currFrame = currFrame;
    // Do not set an impossible value
    if (currFrame >= nFrames) {
        currFrame = 0;
    }
}

}
