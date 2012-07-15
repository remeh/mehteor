#include <string>

#include "ui/texture.h"
#include "ui/bitmap.h"
#include "core/bytebuffer.h"

using namespace std;

namespace meh {

Texture::Texture() :
    bitmap(nullptr) {
    glGenTextures(1, &texId);
}

void Texture::bind(int unit) {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, texId);
}

bool Texture::load(string filename) {
    int width;
    int height;
    int channels;

    // Loads the image 
    unsigned char* img = SOIL_load_image(filename.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);

    if (!img) {
        return false;
    }

    // Store it in a Bitmap
    if (bitmap) {
        delete bitmap;
        bitmap = nullptr;
    }
    int totalSize = width*height*channels;
    bitmap = new Bitmap(totalSize);
    bitmap->buffer().write((char*)img, totalSize); 

    // Create and upload the OpenGL texture using SOIL
    SOIL_create_OGL_texture(img, width, height, channels, texId, SOIL_FLAG_POWER_OF_TWO);

    return true;
}

} // namespace meh
