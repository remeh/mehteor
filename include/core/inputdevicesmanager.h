#ifndef MEH_INPUTDEVICESMANAGER_H
#define MEH_INPUTDEVICESMANAGER_H

#include "core/vector2d.h"

namespace meh {

class InputDevicesManager {
    private:
        /**
         * Mouse position, x-axis.
         */
        int mx;

        /**
         * Mouse position, y-axis.
         */
        int my;

    protected:
    public:
        InputDevicesManager();
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
};

}

#endif // MEH_INPUTDEVICESMANAGER_H
