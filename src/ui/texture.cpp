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

    // Upload the OpenGL texture using SOIL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
    // Was copied into the bitmap buffer.
    SOIL_free_image_data(img);

    return true;
}

} // namespace meh
