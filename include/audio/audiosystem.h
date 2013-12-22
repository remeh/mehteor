#ifndef MEH_AUDIOSYSTEM_H
#define MEH_AUDIOSYSTEM_H

#include <list>

#include "audio/audiosource.h"
#include "audio/sound.h"

using namespace std;

namespace meh
{

#define DEFAULT_SOURCES_COUNT 16

class AudioSystem
{
    private:
        ALCdevice* dvice;
        ALCcontext* cntext;

        list<AudioSource*> srces;

        /**
         * Whether the background thread ticking audio sources is started.
         */
        bool tcking;

        /**
         * The tick is a background thread started on the first played sound.
         * It ticks every sources to see whether a sound is fully played
         * and to restart the play of a sound when its a loop sound
         *
         * @param srces the audio sources list
         */
        static int tick(void* srces);

    protected:
    public:
        /**
         * Init the audio system and reserved the default number of sources.
         */
        AudioSystem();
        /**
         * Init the Audio System and reserved the provided number of sources.
         */
        AudioSystem(unsigned int nbSources);
        /**
         * Destructor.
         */
        ~AudioSystem();

        /**
         * Looks for an empty source and play the provided sound.
         * @param sound the sound to play.
         * @param loop should it be played in loop ?
         */
        void play(Sound* sound, bool loop = false);
};

} // namespace meh

#endif // MEH_AUDIOSYSTEM_H
