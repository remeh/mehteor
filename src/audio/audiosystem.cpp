#include <cstdio> // printf
#include <AL/al.h>
#include <AL/alc.h>
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
        srces.push_back(new AudioSource());
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

void AudioSystem::play(Sound* sound) {
    bool found = false;
    for (auto it = srces.begin(); it != srces.end(); it++) {
        AudioSource* source = *it;
        printf("source %p %i\n", source, source->playing());
        if (!source->playing()) {
            source->play(sound);
            found = true;
            break;
        }
    }

    printf("\n");
    if (!found) {
        printf("ERR: unable to play the provided sound : no sources available.\n");
    }
}

} // namespace meh
