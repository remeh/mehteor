#include "graphics/bitmap.h"

namespace meh {

Bitmap::Bitmap(unsigned int width, unsigned int height, unsigned int channels) :
    width(width),
    height(height),
    chan(channels) {
    bytes.resize(width*height*chan);
}

Bitmap::Bitmap(unsigned int size) :
    width(size),
    height(1),
    chan(3) {
    bytes.resize(size);
}

}
