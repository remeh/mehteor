#include <iostream>
#include <vector>

#include "engine/scene/fontactor.h"
#include "engine/sprite.h"

using namespace std;

namespace meh {

FontActor::FontActor(vector<Sprite*>* sprites) :
    sprtes(sprites) {

}

FontActor::~FontActor() {
    for (auto s = sprtes->begin(); s != sprtes->end(); s++)
    {
        delete (*s);
    }
    if (sprtes) {
        delete sprtes;
    }
}

void FontActor::draw(Renderer* renderer) {
    // renders every glyph.
    for (auto s = sprtes->begin(); s != sprtes->end(); s++)
    {
        renderer->draw(*(*s));
    }
}

void FontActor::update() {
    // nothing to update with fonts sprite.
}

} // namespace meh
