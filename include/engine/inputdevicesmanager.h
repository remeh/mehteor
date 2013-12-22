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

        /**
         * State of mouse buttons.
         */
        bool mouseButtons[3];

    protected:
    public:
        /**
         * Default constructor.
         * @param canvasWidth width of the canvas.
         * @param canvasHeight width of the height.
         */
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
        int getMouseX() {
            return mx;
        }

        /**
         * Returns the mouse position, y-axis.
         * @return the mouse position, y-axis. 
         */
        int getMouseY() {
            return my;
        }

        /**
         * Returns the mouse position.
         */
        Vector2d<int> getMouseXY() {
            return Vector2d<int>(mx,my);
        }

        /**
         * Returns whether a key is pressed.
         */
        bool keyPressed(int key);

        /**
         * Returns whether the left button of the mouse is pressed.
         */
        bool leftButton();

        /**
         * Returns whether the middle button of the mouse is pressed.
         */
        bool middleButton();

        /**
         * Returns whether the right button of the mouse is pressed.
         */
        bool rightButton();
};

}

#endif // MEH_INPUTDEVICESMANAGER_H
