#ifndef MEH_TEXTURE_H
#define MEH_TEXTURE_H

#include <string>
#include <list>
#include <SDL/SDL.h>
#include "GL/glew.h"
#include "SOIL/SOIL.h"

using namespace std;

namespace meh {

class Texture {
        GLuint texId;
        
    private:
    protected:
    public:
        Texture();

        GLuint id() {
            return texId;
        }
};

}

#endif // MEH_TEXTURE_H

