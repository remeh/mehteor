#ifndef MEH_TEXTURE_H
#define MEH_TEXTURE_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "SOIL/SOIL.h"
#include "graphics/bitmap.h"

using namespace std;

namespace meh {

class Texture {
    private:
        Bitmap* bitmap;

        GLuint texId;

        int w;
        int h;

        unsigned char* d;

    protected:
    public:
        Texture();
        Texture(string filename);
        ~Texture();

        /**
         * Binds the texture to the given texture unit.
         * @param unit the unit.
         * @return true if the texture is correctly bound, false whether no texture were loaded before a call to bind()
         */
        bool bind(GLint unit);

        /**
         * Loads the content of an image and upload it to the GPU.
         * @param filename the filename of the image.
         */
        bool load(string filename);

        GLuint id() {
            return texId;
        }

        int width() {
            return w;
        }

        int height() {
            return h;
        }
};

}

#endif // MEH_TEXTURE_H

