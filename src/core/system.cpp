#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <SDL/SDL.h>
#include "GL/glew.h"

#include "core/system.h"

namespace meh {

bool System::initializated = false;
bool System::graphics = false;

void System::init(bool initGraphics) {
    System::graphics = initGraphics;

    if (initGraphics) {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
            // TODO log
            printf("Unable to initialize SDL...\n");
        }
    }

    // Init random seed
    srand(time(NULL));
    System::initializated = true;
}

void System::deinit() {
    SDL_Quit();
}

bool System::isInitializated() {
    return initializated;
}

bool System::graphicsEnabled() {
    return graphics;
}

int System::rnd(int min, int max) {
    return (rand()%(max-min))+min;
}

int System::rnd(int max) {
    return rand()%max;
}

uint32_t System::currentTime() {
    return SDL_GetTicks();
}

void System::sleep(unsigned int ms) {
    SDL_Delay(ms);
}


}
