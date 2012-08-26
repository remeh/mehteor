#include <cstdio> // printf
#include "engine/sprite.h"

namespace meh {

/**
 * The number of vertices for one sprite
 */
int Sprite::VERTEX_SIZE = 3 + 2; // 3 (coord) + 2 (texcoord)
int Sprite::SIZE = 4 * VERTEX_SIZE;

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
    vsible(true) {
    if (texture == nullptr) {
        printf("ERROR: creating a Sprite with a nullptr as texture parameter.\n");
    } else {
        r.setPosition(x, y);
        r.setSize(width, height);
        texRegion = textureRegion;
        rotCenter.setXY(width/2,height/2);
    }
}

Sprite::~Sprite() {

}

void Sprite::setPosition(float x, float y) {
    this->r.setPosition(x,y);
}

void Sprite::setSize(float width, float height) {
    this->r.setSize(width,height);
}

} // namespace meh
