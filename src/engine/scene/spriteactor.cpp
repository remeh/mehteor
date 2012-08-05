#include "engine/scene/spriteactor.h"

namespace meh {

SpriteActor::SpriteActor(Sprite& sprite) :
    s(sprite) {

}

SpriteActor::~SpriteActor() {

}

void SpriteActor::draw(Renderer* renderer) {
    renderer->draw(s);
}

}
