#ifndef MEH_BMGLYPHINFO_H
#define MEH_BMGLYPHINFO_H

#include <string>
#include <fstream>

using namespace std;

namespace meh {

/**
 * Texture information of a glyph.
 * 
 * @author Rémy 'remeh' MATHIEU
 */
class BMGlyphInfo {
    private:
        int _id;

        int _x;

        int _y;

        int wdth;

        int hght;

        int xffset;

        int yffset;

        int xdvance;

        int pge;

        int chnnel;

    protected:
    public:
       BMGlyphInfo(int id, int x, int y, int width, int height, int xoffset, int yoffset, int xadvance, int page, int channel);

        ~BMGlyphInfo();

        int id() { return _id; }
        int x() { return _x; }
        int y() { return _y; }
        int width() { return wdth; }
        int height() { return hght; }
        int xOffset() { return xffset; }
        int yOffset() { return yffset; }
        int xAdvance() { return xdvance; }
        int page() { return pge; }
        int channel() { return chnnel; }
};

} // namespace meh

#endif // MEH_BMGLYPHINFO_H


