#ifndef MEH_CANVAS_H
#define MEH_CANVAS_H

#include <string>
#include <SDL/SDL.h>
#include "core/vector2d.h"
#include "engine/inputdevicesmanager.h"

using namespace std;

namespace meh 
{

class Canvas 
{
    private:
        SDL_Surface* sdlSurface;

        // Init GLEW once
        static bool glewIsInit;

        /**
         * EventsManager of this Canvas.
         */
        InputDevicesManager inputManager;

    protected:
    public:
        /**
         * Default constructor.
         *
         * @param w width of this canvas
         * @param h height of this canvas
         */
        Canvas(int w, int h);
        virtual ~Canvas();

        /**
         * Clears the screen with the provided color.
         */
        void clear(float r, float g, float b, float a);

        /**
         * Returns the pointer to the SDL_Surface.
         * @return the pointer to the SDL_Surface.
         */
        SDL_Surface* getSurface() 
        {
            return sdlSurface;
        }

        /**
         * Returns the width of this canvas
         */
        int getWidth() const
        {
            if (sdlSurface)
                return sdlSurface->w; 
            return -1;
        }

        /**
         * Returns the height of this canvas.
         */
        int getHeight() const 
        {
            if (sdlSurface)
                return sdlSurface->h; 
            return -1;
        }

        /**
         * Sets the title of the window.
         *
         * @param title the new title of the window
         */
        void setTitle(string title);

        /**
         * Flips the buffer of the Canvas.
         *
         * When you draw on the Canvas, you don't actually draw
         * directly on it but in another buffer. When you flip
         * the Canvas, you display the modified buffer.
         */
        void flip();

        InputDevicesManager& getInputDevicesManager()
        {
            return inputManager;
        }
};

} // namespace meh

#endif // MEH_CANVAS_H
