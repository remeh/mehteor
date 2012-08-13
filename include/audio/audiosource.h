#ifndef MEH_AUDIOSOURCE_H
#define MEH_AUDIOSOURCE_H

#include <AL/al.h>
#include "core/system.h"
#include "audio/sound.h"

namespace meh {

class AudioSource {
    private:
        ALuint srcId;
        ALuint buffId;
        bool plying;

        Sound* snd;
        /**
         * When reading a sound, endTime is set at approximatly
         * what time the sound is fully played (using System::currentTime())
         */
        unsigned int endTime;
        static int staticPlay(void* param);

    protected:
    public:
        /**
         * Allocates and creates an AudioSource.
         */
        AudioSource();
        ~AudioSource();

        bool playing() {
            // If the source isn't a loop and has finished
            // to play the sound
            if (System::currentTime() > endTime) {
                plying = false;
            }
            return plying;
        }

        void play(Sound* sound);
};

} // namespace meh 

#endif // MEH_AUDIOSOURCE_H
