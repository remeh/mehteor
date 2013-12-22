#include <cstdio>
#include <string>
#ifdef __APPLE__
    #include <OpenAL/al.h>
    #include <OpenAL/alc.h>
#else
    #include <AL/al.h>
    #include <AL/alc.h>
#endif
#ifdef WIN32 // mingw missed a definition 
#define fseeko64 fseek
#endif
#include <vorbis/vorbisfile.h>

#include "audio/sound.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32768
#endif

using namespace std;

namespace meh
{

Sound::Sound(string filename) :
    frmat(AL_FORMAT_MONO16),
    freq(-1) {
    dta.clear();
    // OK, epic shortcut, but as of today, assumes it's an ogg file
    loadOgg(filename); 
}

Sound::~Sound()
{
    dta.clear();
}

void Sound::loadOgg(string filename)
{
    long reading = 1;
    int bitStream;
    char buff[BUFFER_SIZE];
    FILE* file;
    vorbis_info* vInfo;
    OggVorbis_File oggFile;

    file = fopen(filename.c_str(), "rb");
    
    if (!file)
    {
        printf("ERR: unable to open the sound %s\n",filename.c_str());
        dta.clear();
        return;
    }

    // Open the Ogg
    ov_open(file, &oggFile, nullptr, 0);

    // Retrieve infos
    vInfo = ov_info(&oggFile, -1);

    // Format
    frmat = AL_FORMAT_MONO16;
    if (vInfo->channels != 1)
    {
        frmat = AL_FORMAT_STEREO16;
    }

    // Frequency
    freq = vInfo->rate;

    dration = static_cast<unsigned int>(ov_time_total(&oggFile, -1)*1000);

    // Data
    do 
    {
        reading = ov_read(&oggFile, buff, BUFFER_SIZE, 0, 2, 1, &bitStream);
        dta.insert(dta.end(), buff, buff+reading);
    } while (reading > 0);

    // Release the resource
    ov_clear(&oggFile);
    // No-need to call fclose on 'file', already managed by Vorbis.
    vInfo = nullptr;
    file = nullptr;
}

} // namespace meh
