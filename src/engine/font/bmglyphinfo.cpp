#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "engine/font/bmglyphinfo.h"

namespace meh {

BMGlyphInfo::BMGlyphInfo(int id, int x, int y, int width, int height, int xoffset, int yoffset, int xadvance, int page, int channel) :
    _id(id), _x(x), _y(y), wdth(width), hght(height), xffset(xoffset), yffset(yoffset), xdvance(xadvance), pge(page), chnnel(channel) {
}

BMGlyphInfo::~BMGlyphInfo() {
}

} // namespace meh
