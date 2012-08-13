#ifndef MEH_AUDIOSYSTEM_H
#define MEH_AUDIOSYSTEM_H

#include <list>

#include "audio/audiosource.h"
#include "audio/sound.h"

using namespace std;

namespace meh {

#define DEFAULT_SOURCES_COUNT 8

class AudioSystem {
    private:
        ALCdevice* dvice;
        ALCcontext* cntext;

        list<AudioSource*> srces;

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

        ~AudioSystem();

        /**
         * Looks for an empty source and play the provided sound.
         * @param sound the sound to play.
         */
        void play(Sound* sound);
};

} // namespace meh

#endif // MEH_AUDIOSYSTEM_H
