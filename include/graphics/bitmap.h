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
        unsigned int chan;
        ByteBuffer bytes;

    protected:
    public:
        /**
         * Default constructor.
         * Allocates the needed memory.
         * @param width the width of this image
         * @param height the height of this image
         * @param channels how many bytes are used for a pixel
         */
        Bitmap(unsigned int width, unsigned int height, unsigned channels = 1);

        /**
         * Default constructor
         * Allocates the needed memory. The width will be equal to the size, the height
         * and the channel will be equal to 1.
         */
        Bitmap(unsigned int size);

        /**
         * Returns the width of this Bitmap.
         * @return the width of this Bitmap.
         */
        unsigned int w() { 
            return width;
        }

        /**
         * Returns the height of this Bitmap.
         * @return the height of this Bitmap.
         */
        unsigned int h() {
            return height;
        }

        /**
         * Returns how many bytes are used for a pixel.
         * @return how many bytes are used for a pixel. 
         */
        unsigned int channels() {
            return chan;
        }

        ByteBuffer& buffer() {
            return bytes;
        }
};

}

#endif // MEH_BITMAP_H

