#include <cstdio> // printf
#include <SDL/SDL_thread.h>
#include "core/system.h"
#include "audio/audiosource.h"
#include "audio/sound.h"

namespace meh {

AudioSource::AudioSource() :
    plying(false),
    lping(false),
    snd(nullptr),
    endTime(0) {
    alGenSources(1, &srcId); 
    alGenBuffers(1, &buffId);
    if (alGetError() != AL_FALSE) {
        printf("ERR: Unable to generate an audio source.\n");
    }
    // Source position to default 0,0,0
    alSource3f(srcId, AL_POSITION, 0.0f, 0.0f, 0.0f);
}

AudioSource::~AudioSource() {
    if (buffId > 0) {
        alDeleteBuffers(1, &buffId);
    }
    if (srcId > 0) {
        alDeleteSources(1, &srcId);
    }
}

/*static*/ int AudioSource::staticPlay(void* param) {
    int srcId = *(static_cast<int*>(param));
    // play
    alSourcePlay(srcId);
    int state = 1;
    do {
        alGetSourcei(srcId,AL_SOURCE_STATE,&state);
        // XXX as of today (2012-08-22), 10ms is an arbitrary value
        System::sleep(10);
    } while (state != AL_STOPPED);
    return 0;
}

void AudioSource::play(Sound* sound, bool loop) {
    if (sound == nullptr) {
        printf("WARN: tried to play a nullptr sound.\n");
        return;
    }
    snd = sound;
    plying = true;
    lping = loop;
    // put the sound data into the buffer
    alBufferData(buffId, sound->format(), &(sound->data()[0]), static_cast<ALsizei>(sound->data().size()), sound->frequency());
    // attach the buffer to the source
    alSourcei(srcId, AL_BUFFER, buffId);
    // compute in how many milli-seconds this Sound will be fully played.
    endTime = System::currentTime() + sound->duration() + 15;
    // launch the thread actually reading the sound
    SDL_CreateThread(&AudioSource::staticPlay, &srcId);
}

void AudioSource::tick() {
    if (System::currentTime() > endTime) {
        plying = false;
    }
    if (lping && !plying) {
       play(snd,true); 
    }
}

}

