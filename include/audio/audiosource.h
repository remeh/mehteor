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
        /**
         * Is this audio source playing ?
         */
        bool plying;
        /**
         * Is this audio source looping ?
         */
        bool lping;
        /**
         * Used to relaunch the reading if looping,
         * DO NOT FREE ITS MEMORY.
         */
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

        /**
         * Returns whether the audio source is playing.
         */
        bool playing() {
            return plying;
        }

        /**
         * Returns whether this audio source plays a loop sound.
         */
        bool looping() {
            return lping;
        }

        /**
         * Plays a sound.
         * @param sound the sound to play.
         * @param loop does this sound be played in loop ?
         */
        void play(Sound* sound, bool loop = false);

        /**
         * Returns the OpenAL source id.
         */
        ALuint sourceId() {
            return srcId;
        }

        /**
         * The AudioSystem used this method to tick the audio source.
         * The AudioSource when ticked, look whether it shouldn't restart
         * a sound (when it's a loop sound).
         */
        void tick();
};

} // namespace meh 

#endif // MEH_AUDIOSOURCE_H
