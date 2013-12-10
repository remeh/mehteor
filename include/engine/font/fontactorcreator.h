#ifndef MEH_FONTACTORCREATOR_H
#define MEH_FONTACTORCREATOR_H

#include <map>
#include <string>

#include "graphics/texture.h"
#include "engine/sprite.h"
#include "engine/resourcesmanager.h"
#include "engine/scene/fontactor.h"
#include "engine/font/bmglyphinfo.h"

using namespace std;

namespace meh {

class FontActorCreator {
    private:
        map<int, BMGlyphInfo>* glphInfos;

        /**
         * For texture.
         */
        ResourcesManager& resources;
        
    protected:
    public:
        FontActorCreator(ResourcesManager& resourcesManager, map<int, BMGlyphInfo>* glyphInfos); // TODO GlyphInfo more abstract, not specific to BMFont
        ~FontActorCreator();

        FontActor* createFontActor(string textureName, string text, int x, int y);
};

} // namespace meh

#endif // MEH_FONTACTORCREATOR_H
