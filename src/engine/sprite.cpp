#include "engine/sprite.h"

namespace meh {

Sprite::Sprite(Texture& texture) :
    tex(texture),
    r(0.0f,0.0f,texture.width(),texture.height()),
    scleX(1.0f),
    scleY(1.0f),
    texRegion(0.0f,0.0f,texture.width(),texture.height()) {

}

Sprite::~Sprite() {

}

} // namespace meh
