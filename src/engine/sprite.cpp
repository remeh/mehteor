#include <cstdio> // printf
#include <string>
#include "engine/sprite.h"
#include "engine/spriteanimation.h"

namespace meh {

/**
 * The number of vertices for one sprite
 */
int Sprite::VERTEX_SIZE = 3 + 2; // 3 (coord) + 2 (texcoord)
int Sprite::SIZE = 4 * VERTEX_SIZE;
string Sprite::DEFAULT_ANIMATION = "default"; 

Sprite::Sprite(Texture* texture) : 
    Sprite(texture,
            0.0f, 0.0f,
            texture ? texture->width() : 0.0f, texture ? texture->height() : 0.0f) {
}

Sprite::Sprite(Texture* texture, float x, float y) :
    Sprite(texture,
            x, y,
            texture ? texture->width() : 0.0f, texture ? texture->height() : 0.0f) {
}

Sprite::Sprite(Texture* texture, float x, float y, float width, float height) :
    Sprite(texture,
            x,y,
            width,height,
            Rect<float>(0.0f, 0.0f, texture ? texture->width() : 0.0f, texture ? texture->height() : 0.0f)) {

}

Sprite::Sprite(Texture* texture, float x, float y, float width, float height, Rect<float> textureRegion) :
    tex(texture),
    scleX(1.0f),
    scleY(1.0f),
    rot(0.0f),
    vsible(true),
    currAnimation(nullptr) {
    if (texture == nullptr) {
        printf("ERROR: creating a Sprite with a nullptr as texture parameter.\n");
    } else {
        r.setPosition(x, y);
        r.setSize(width, height);
        unsigned int duration[] = { 10000 };
        Rect<float> texCoords[] = { textureRegion };

        // adds the default animation.
        addAnimation(Sprite::DEFAULT_ANIMATION, 1, duration, texCoords);
        currAnimation = anims[Sprite::DEFAULT_ANIMATION];
        currAnimation->reset();

        rotCenter.setXY(width/2,height/2);
    }
}

Sprite::~Sprite() {
    for (auto it = anims.begin(); it != anims.end(); it++) {
        delete (it->second);
    }
    anims.clear();
}

void Sprite::setPosition(float x, float y) {
    this->r.setPosition(x,y);
}

void Sprite::setSize(float width, float height) {
    this->r.setSize(width,height);
}

void Sprite::addAnimation(string name, int nbFrames, const unsigned int* durations, const Rect<float>* texCoords) {
   SpriteAnimation* animation = new SpriteAnimation(name, nbFrames, durations, texCoords);
   anims[name] = animation;
}

bool Sprite::setAnimation(string name) {
    if (anims.count(name) == 1) {
        currAnimation = anims[name];
        currAnimation->reset();
    }
    return false;
}

SpriteAnimation& Sprite::currentAnimation() {
    return *currAnimation;
}

Rect<float>& Sprite::textureRegion() {
    return currentAnimation().textureRegion();
}

void Sprite::update() {
    // updates the animation
    currentAnimation().update();
}

} // namespace meh
