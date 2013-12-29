#include "core/mutex.h"

namespace meh
{

Mutex::Mutex() :
    mutex(nullptr)
{
    this->mutex = SDL_CreateMutex();
}

Mutex::~Mutex()
{
    if (mutex != nullptr)
    {
        SDL_DestroyMutex(this->mutex);
    }
}

int Mutex::lock()
{
    return SDL_LockMutex(this->mutex);
}

int Mutex::unlock()
{
    return SDL_UnlockMutex(this->mutex);
}

SDL_mutex* Mutex::getSDLMutex()
{
    return mutex;
}

} // namespace meh
