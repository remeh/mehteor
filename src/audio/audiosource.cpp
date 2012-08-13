#include <cstdio> // printf
#include <SDL/SDL_thread.h>
#include "core/system.h"
#include "audio/audiosource.h"
#include "audio/sound.h"

namespace meh {

AudioSource::AudioSource() :
    plying(false),
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
    if (srcId > 0) {
        alDeleteSources(1, &srcId);
    }
    if (buffId > 0) {
        alDeleteBuffers(1, &buffId);
    }
}

void AudioSource::play(Sound* sound) {
    if (sound == nullptr) {
        printf("WARN: tried to play a nullptr sound.\n");
        return;
    }

    plying = true;
    // put the sound data into the buffer
    alBufferData(buffId, sound->format(), &(sound->data()[0]), static_cast<ALsizei>(sound->data().size()), sound->frequency());
    // attach the buffer to the source
    alSourcei(srcId, AL_BUFFER, buffId);
    // compute in how many milli-seconds this Sound will be fully played.
    endTime = System::currentTime() + sound->duration() + 30;
    // launch the thread actually reading the sound
    /*SDL_Thread* thread =*/ SDL_CreateThread(&AudioSource::staticPlay, &srcId);
    // SDL_WaitThread(thread, nullptr);
}

int AudioSource::staticPlay(void* param) {
    int srcId = *(static_cast<int*>(param));
    printf("srcId : %i\n",srcId);
    // play
    alSourcePlay(srcId);
    if (alGetError() != AL_FALSE) {
        printf("err..\n");
    }
    int state = 1;
    do {
        alGetSourcei(srcId,AL_SOURCE_STATE,&state);
    } while (state != AL_STOPPED);
    printf("?\n");
    return 0;
}

}

