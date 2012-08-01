#include <cstdio> // printf
#include "engine/sprite.h"

namespace meh {

/**
 * The number of vertices for one sprite
 */
int Sprite::VERTEX_SIZE = 2 + 2; // 2 (coord) + 2 (texcoord)
int Sprite::SIZE = 4 * VERTEX_SIZE;

Sprite::Sprite(Texture* texture) :
    tex(texture),
    scleX(1.0f),
    scleY(1.0f) {
    if (texture == nullptr) {
        printf("ERROR: creating a Sprite with a nullptr as texture parameter.\n");
    } else {
        r.setPosition(0.0f, 0.0f);
        r.setSize(texture->width(), texture->height());
        texRegion.setPosition(0.0f,0.0f);
        texRegion.setSize(texture->width(), texture->height());
    }
}

Sprite::~Sprite() {

}

void Sprite::setPosition(float x, float y) {
    this->r.setPosition(x,y);
}

} // namespace meh
