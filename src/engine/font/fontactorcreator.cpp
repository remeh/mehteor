#include <iostream>
#include <string>
#include <vector>

#include "engine/font/fontactorcreator.h"
#include "engine/sprite.h"

using namespace std;

namespace meh {

FontActorCreator::FontActorCreator(ResourcesManager& resourcesManager, map<int, BMGlyphInfo>* glyphInfos)
    : glphInfos(glyphInfos),resources(resourcesManager) {

}

FontActorCreator::~FontActorCreator() {
    if (glphInfos) {
        delete glphInfos;
    }
}

FontActor* FontActorCreator::createFontActor(string textureName, string text, int x, int y) {
    Texture* tex = resources.getTexture(textureName);

    vector<Sprite*>* sprites = new vector<Sprite*>();

    int xpos = x;
    int width = 0;

    for (unsigned int i = 0; i < text.length(); i++) {
        char c = text.at(i);
        BMGlyphInfo& info = glphInfos->at(c);
        
        // FIXME ugly fix to fix the space problem
        if (c == ' ') {
            width = 8;
        } else {
            width = info.width();
        }

        sprites->push_back(new Sprite(tex, xpos, y, width, info.height(), Rect<float>(info.x(),info.y(),info.width(),info.height())));

        xpos += width;
    }

    return new FontActor(sprites);    
}

} // namespace meh
