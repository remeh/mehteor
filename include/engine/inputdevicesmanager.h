#ifndef MEH_INPUTDEVICESMANAGER_H
#define MEH_INPUTDEVICESMANAGER_H

#include "core/vector2d.h"

namespace meh {

#ifndef MEH_MOUSE_LEFT_BUTTON
#define MEH_MOUSE_LEFT_BUTTON 0
#define MEH_MOUSE_MIDDLE_BUTTON 1
#define MEH_MOUSE_RIGHT_BUTTON 2
#endif

/**
 * Simple input devices manager implementation for computers (keyboard and a simple mouse).
 */
class InputDevicesManager {
    private:
        int canvasWidth;
        int canvasHeight;
        
        /**
         * Mouse position, x-axis.
         */
        int mx;

        /**
         * Mouse position, y-axis.
         */
        int my;

        /**
         * States of every keys.
         */
        bool keys[SDLK_LAST]; 

        bool mouseButtons[3];

    protected:
    public:
        InputDevicesManager(int canvasWidth, int canvasHeight);
        ~InputDevicesManager();

        /**
         * Polls every input events to update the keyboard/mouse states.
         */
        void update();

        /**
         * Returns the mouse position, x-axis.
         * @return the mouse position, x-axis.
         */
        int mouseX() {
            return mx;
        }

        /**
         * Returns the mouse position, y-axis.
         * @return the mouse position, y-axis. 
         */
        int mouseY() {
            return my;
        }

        /**
         * Returns the mouse position.
         */
        Vector2d<int> mouseXY() {
            return Vector2d<int>(mx,my);
        }

        bool keyPressed(int key);

        bool leftButton();
        bool middleButton();
        bool rightButton();
};

}

#endif // MEH_INPUTDEVICESMANAGER_H
