#include <string>
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "core/system.h"
#include "graphics/canvas.h"

using namespace std;

namespace meh {

bool Canvas::glewIsInit = false;

Canvas::Canvas(int w, int h) :
    sdlSurface(nullptr),
    inputManager(w,h) {
    if (System::graphicsEnabled()) {
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
        sdlSurface = SDL_SetVideoMode(w,h,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
        
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        
        // Init OpenGL extensions and check versions
        glewExperimental = GL_TRUE;
        if (!Canvas::glewIsInit) {
            if (glewInit() != GLEW_OK) {
                printf("Unable to initialize GLEW...\n");
                Canvas::glewIsInit = true;
            } else {
                printf("GLEW initializated.\n");
            }
            const unsigned char* version = glGetString(GL_VERSION);
            printf("GL version : %s\n",version);
            if (version[0] != '3' && version[0] != '4') {
                printf("ERROR: OpenGL version < 3.\nMehteor could not work correctly.\n");
            } else if (version[0] == '1')
            {
                printf("ERROR: OpenGL 1.x detected,\nMehteor will probably not work correctly.\n");
            }
            version = glGetString(GL_SHADING_LANGUAGE_VERSION);
            printf("GLSL version : %s\n",version);
        }
    } else {
        printf("ERROR: Mehteor graphics disabled. You can't create a Canvas.\n");
    }
}

Canvas::~Canvas() {
    // sdlSurface is freed by SDL_Quit() and should not be freed here.
}

void Canvas::flip() {
    SDL_GL_SwapBuffers();
}

void Canvas::setTitle(string title) {
    SDL_WM_SetCaption(title.c_str(),nullptr);
}

void Canvas::clear(float r, float g, float b, float a) {
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace meh
