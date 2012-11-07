#include <cstdio> // printf
#include <SDL/SDL_thread.h>
#ifdef __APPLE__
    #include <OpenAL/al.h>
    #include <OpenAL/alc.h>
#else
    #include <AL/al.h>
    #include <AL/alc.h>
#endif
#include "audio/audiosystem.h"
#include "audio/sound.h"

namespace meh {

AudioSystem::AudioSystem() :
    AudioSystem(DEFAULT_SOURCES_COUNT) {
}

AudioSystem::AudioSystem(unsigned int nbSources) :
    dvice(nullptr),
    cntext(nullptr) {

    dvice = alcOpenDevice(nullptr);
    if (dvice == nullptr) {
        printf("ERR: unable to open the audio device.\n");
        return;
    }

    cntext = alcCreateContext(dvice, nullptr);
    alcMakeContextCurrent(cntext);
    alcProcessContext(cntext);

    if (alGetError() != AL_FALSE) {
        printf("ERR: unable to create the audio context.\n");
        return;
    }

    for (unsigned int i = 0; i < nbSources; i++) {
        AudioSource* src = new AudioSource();
        if (src->sourceId() != 0) {
            srces.push_back(new AudioSource());
        } else {
            delete src;
        }
    }

    // Listener position to default 0,0,0
    alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

    if (alGetError() != AL_FALSE) {
        printf("ERR: unable to set the listener position.\n");
        return;
    }
}

AudioSystem::~AudioSystem() {
    for (auto it = srces.begin(); it != srces.end(); it++) {
        delete *it;
    }
    srces.clear();
    if (dvice) {
        alcCloseDevice(dvice);
    }
    if (cntext) {
        alcDestroyContext(cntext);
    }
}

void AudioSystem::play(Sound* sound, bool loop) {
    // The background thread isn't started,
    // starts it
    if (!tcking) {
        SDL_CreateThread(&AudioSystem::tick, &srces);
        tcking = true;
    }

    bool found = false;
    for (auto it = srces.begin(); it != srces.end(); it++) {
        AudioSource* source = *it;
        if (!source->playing()) {
            source->play(sound,loop);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("ERR: unable to play the provided sound : no sources available.\n");
    }
}

/*static*/ int AudioSystem::tick(void* srces) {
    list<AudioSource*>& sources = *(static_cast<list<AudioSource*>*>(srces)); 
    while (1) {
        for (AudioSource* source : sources) {
            source->tick();
        }
        // Don't refresh too much
        // XXX as of today (2012-08-22), 250ms is an arbitrary value
        System::sleep(250);
    }
    return 0;
}

} // namespace meh
