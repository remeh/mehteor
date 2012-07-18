#include <SDL/SDL.h>
#include "core/inputdevicesmanager.h"

namespace meh {

InputDevicesManager::InputDevicesManager() :
    mx(0),
    my(0) {

}

InputDevicesManager::~InputDevicesManager() {

}

void InputDevicesManager::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                mx = event.motion.x;
                my = event.motion.y;
                break;
        }
    }
}

}
