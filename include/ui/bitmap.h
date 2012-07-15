#ifndef MEH_BITMAP_H
#define MEH_BITMAP_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "SOIL/SOIL.h"
#include "core/bytebuffer.h"

using namespace std;

namespace meh {

class Bitmap {
    private:
        unsigned int width;
        unsigned int height;
        ByteBuffer bytes;

    protected:
    public:
        /**
         * Default constructor.
         * Allocates the needed memory.
         */
        Bitmap(unsigned int width, unsigned int height);

        /**
         * Default constructor
         * Allocates the needed memory. The width will be equal to the size and the height
         * will be equal to 1.
         */
        Bitmap(unsigned int size);

        /**
         * Returns the width of this Bitmap.
         */
        unsigned int w() { 
            return width;
        }

        /**
         * Returns the height of this Bitmap.
         */
        unsigned int h() {
            return height;
        }

        ByteBuffer& buffer() {
            return bytes;
        }
};

}

#endif // MEH_BITMAP_H

