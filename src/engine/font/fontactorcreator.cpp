#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "engine/font/fontactorcreator.h"
#include "engine/sprite.h"

using namespace std;

namespace meh {

FontActorCreator::FontActorCreator(ResourcesManager& resourcesManager, map<int, BMGlyphInfo>* glyphInfos)
    : glphInfos(glyphInfos),resources(resourcesManager) 
{
}

FontActorCreator::~FontActorCreator() 
{
    if (glphInfos) 
    {
        delete glphInfos;
    }
}

shared_ptr<FontActor> FontActorCreator::createFontActor(string textureName, string text, float x, float y)
{
    return createFontActor(textureName, text, x, y, 1.0f, Vector4d<float>(1.0f,1.0f,1.0f,1.0f));
}

shared_ptr<FontActor> FontActorCreator::createFontActor(string textureName, string text, float x, float y, Vector4d<float> tint)
{
    return createFontActor(textureName, text, x, y, 1.0f, tint);
}

shared_ptr<FontActor> FontActorCreator::createFontActor(string textureName, string text, float x, float y, float scale)
{
    return createFontActor(textureName, text, x, y, scale, Vector4d<float>(1.0f,1.0f,1.0f,1.0f));
}

shared_ptr<FontActor> FontActorCreator::createFontActor(string textureName, string text, float x, float y, float scale, Vector4d<float> tint) 
{
    Texture* tex = resources.getTexture(textureName);

    vector< shared_ptr<Sprite> >* sprites = new vector< shared_ptr<Sprite> >();

    int xpos = x;
    int width = 0;

    for (unsigned int i = 0; i < text.length(); i++) 
    {
        char c = text.at(i);
        BMGlyphInfo& info = glphInfos->at(c);

        // FIXME ugly fix to fix the space problem
        if (c == ' ')
        {
            width = 8*scale;
        }
        else
        {
            width = info.width()*scale;
        }
        
        
        shared_ptr<Sprite> sprite = shared_ptr<Sprite>(new Sprite(tex, xpos, y, width, info.height()*scale, Rect<float>(info.x(),info.y(),info.width(),info.height())));
        sprite->setTint(tint);
        sprites->push_back(sprite);

        xpos += width;
    }

    return shared_ptr<FontActor>(new FontActor(sprites));
}

} // namespace meh
