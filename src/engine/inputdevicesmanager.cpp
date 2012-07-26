#include <SDL/SDL.h>
#include "engine/inputdevicesmanager.h"

namespace meh {

InputDevicesManager::InputDevicesManager(int canvasWidth, int canvasHeight) :
    canvasWidth(canvasWidth),
    canvasHeight(canvasHeight),
    mx(0),
    my(0) {
    mouseButtons[0] = mouseButtons[1] = mouseButtons[2] = false;
    for (int i = 0; i < SDLK_LAST; i++) {
        keys[i] = false;
    }
}

InputDevicesManager::~InputDevicesManager() {

}

void InputDevicesManager::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                keys[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                keys[event.key.keysym.sym] = false;
                break;
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                       mouseButtons[MEH_MOUSE_LEFT_BUTTON] = false;
                       break;
                    case SDL_BUTTON_MIDDLE:
                       mouseButtons[MEH_MOUSE_MIDDLE_BUTTON] = false;
                       break;
                    case SDL_BUTTON_RIGHT:
                       mouseButtons[MEH_MOUSE_RIGHT_BUTTON] = false;
                       break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                       mouseButtons[MEH_MOUSE_LEFT_BUTTON] = true;
                       break;
                    case SDL_BUTTON_MIDDLE:
                       mouseButtons[MEH_MOUSE_MIDDLE_BUTTON] = true;
                       break;
                    case SDL_BUTTON_RIGHT:
                       mouseButtons[MEH_MOUSE_RIGHT_BUTTON] = true;
                       break;
                }
                break;
            case SDL_MOUSEMOTION:
                mx = event.motion.x;
                my = canvasHeight-event.motion.y;
                break;
        }
    }
}

bool InputDevicesManager::keyPressed(int key) {
    if (key > SDLK_LAST || key < 0) {
        return false;
    }
    return keys[key];
}

bool InputDevicesManager::leftButton() {
    return mouseButtons[MEH_MOUSE_LEFT_BUTTON];
}

bool InputDevicesManager::rightButton() {
    return mouseButtons[MEH_MOUSE_RIGHT_BUTTON];
}

bool InputDevicesManager::middleButton() {
    return mouseButtons[MEH_MOUSE_MIDDLE_BUTTON];
}

}
