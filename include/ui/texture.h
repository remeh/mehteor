#ifndef MEH_TEXTURE_H
#define MEH_TEXTURE_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "SOIL/SOIL.h"
#include "ui/bitmap.h"

using namespace std;

namespace meh {

class Texture {
        GLuint texId;
        
    private:
        /**
         * Updates the texture pixels on the GPU.
         */
        void updateGPU();
        Bitmap* bitmap;

    protected:
    public:
        Texture();

        /**
         * Binds the texture to the given texture unit.
         * @param unit the unit.
         */
        void bind(GLint unit);

        /**
         * Loads the content of an image and upload it to the GPU.
         * @param filename the filename of the image.
         */
        bool load(string filename);

        GLuint id() {
            return texId;
        }
};

}

#endif // MEH_TEXTURE_H

