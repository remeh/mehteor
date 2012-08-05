#ifndef MEH_SPRITE_ANIMATION_H
#define MEH_SPRITE_ANIMATION_H

#include <string>

#include "core/rect.h"

using namespace std;

namespace meh {

class SpriteAnimation {
    private:
        unsigned int nFrames;
        unsigned int currFrame;
        unsigned int* durations;
        Rect<float>* texCoords;
        double nextFrame;
        string n;

    protected:
    public:
        /**
         * Default constructor.
         *
         * @param name name of the animation
         * @param nbFrames the number of frames of this animation
         * @param durations the duration of each frame of this animation
         * @param texCoords the texture coordinates of each frame of this animation
         */
        SpriteAnimation(string name, unsigned int nbFrames, const unsigned int* durations, const Rect<float>* texCoords);
        ~SpriteAnimation();

        /**
         * Refresh the animation if needed.
         *
         * \return true whether the frame has changed
         */
        bool tick();

        /**
         * Returns the must-be currently
         * displayed frame texture coordinates.
         */
        Rect<float>& getCurrentTexCoords() {
            return texCoords[currFrame];
        }

        /**
         * Returns the name of this animation.
         */
        string name() {
            return n;
        }

        /**
         * Returns the number of the current frame.
         */
        unsigned int currentFrame() {
            return currFrame;
        }

        /**
         * Sets the current frame by its number.
         *
         * @param currentFrame the number of the frame
         */
        void setCurrentFrame(unsigned int currentFrame);
};

} // namespace meh

#endif // MEH_SPRITE_ANIMATION_H

