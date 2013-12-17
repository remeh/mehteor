#ifndef MEH_FONTACTORCREATOR_H
#define MEH_FONTACTORCREATOR_H

#include <map>
#include <string>

#include "core/vector4d.h"
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

        FontActor* createFontActor(string textureName, string text, float x, float y);
        FontActor* createFontActor(string textureName, string text, float x, float y, Vector4d<float> tint);
        FontActor* createFontActor(string textureName, string text, float x, float y, float scale);
        FontActor* createFontActor(string textureName, string text, float x, float y, float scale, Vector4d<float> tint);
};

} // namespace meh

#endif // MEH_FONTACTORCREATOR_H
