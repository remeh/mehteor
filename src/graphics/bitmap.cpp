#include "graphics/bitmap.h"

namespace meh {

Bitmap::Bitmap(unsigned int width, unsigned int height) :
    width(width),
    height(height) {
    bytes.resize(width*height);
}

Bitmap::Bitmap(unsigned int size) :
    width(size),
    height(1) {
    bytes.resize(size);
}

}
