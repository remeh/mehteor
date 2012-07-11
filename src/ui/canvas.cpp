#include <string>
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "ui/canvas.h"

using namespace std;

namespace meh {

bool Canvas::glewIsInit = false;

Canvas::Canvas(int w, int h) :
    sdlSurface(nullptr) {
    sdlSurface = SDL_SetVideoMode(w,h,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
    
    // Init OpenGL extensions
    glewExperimental = GL_TRUE;
    if (!Canvas::glewIsInit) {
        if (glewInit() != GLEW_OK) {
            printf("Unable to initialize GLEW...\n");
            Canvas::glewIsInit = true;
        }
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

} // namespace meh
