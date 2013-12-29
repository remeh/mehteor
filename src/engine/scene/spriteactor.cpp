#include "engine/scene/spriteactor.h"
#include "engine/sprite.h"

namespace meh {

SpriteActor::SpriteActor(Sprite& sprite) :
    s(sprite) {

}

SpriteActor::~SpriteActor() {

}

void SpriteActor::draw(Renderer* renderer) {
    renderer->draw(s);
}

void SpriteActor::update() {
    s.update();
}

}
