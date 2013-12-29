#include <string>

#include "graphics/texture.h"
#include "graphics/bitmap.h"
#include "core/bytebuffer.h"

using namespace std;

namespace meh {

Texture::Texture() :
    bitmap(nullptr) 
{
    glGenTextures(1, &texId);
}

Texture::Texture(string filename) :
    bitmap(nullptr) 
{
    glGenTextures(1, &texId);
    load(filename);
}

Texture::~Texture() 
{
    glDeleteTextures(1, &texId);
    if (bitmap)
    {
        delete bitmap;
        bitmap = nullptr;
    }
}

bool Texture::bind(int unit) 
{
    if (!bitmap) 
    {
        return false;
    }
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, texId);
    return true;
}

bool Texture::load(string filename) 
{
    int width;
    int height;
    int channels;

    // Loads the image, force to 4 channels
    unsigned char* img = SOIL_load_image(filename.c_str(), &width, &height, &channels, SOIL_LOAD_RGBA);
    channels = 4; // we've forced to 4

    if (!img) 
    {
        return false;
    }

    // Store it in a Bitmap
    if (bitmap) 
    {
        delete bitmap;
        bitmap = nullptr;
    }
    w = width;
    h = height;

    /*
     * Loads it in a Bitmap
     */
    int totalSize = width*height*channels;
    bitmap = new Bitmap(width,height,channels);
    bitmap->getBuffer().reset();
    bitmap->getBuffer().write(img, totalSize);

    // Upload the OpenGL texture loaded by SOIL
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap->getBuffer().getData());

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    return true;
}

} // namespace meh
