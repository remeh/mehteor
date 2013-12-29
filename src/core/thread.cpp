#include <string>
#include "core/thread.h"

using namespace std;

namespace meh
{

Thread::Thread(string name, int func(void*), void* args) :
    name(name),
    running(false)
//  detached(false)
{
    thread = SDL_CreateThread(func, args);

    if (thread != nullptr)
    {
        running = true;
    }
}

Thread::~Thread()
{
}

SDL_Thread* Thread::getSDLThread()
{
    return thread;
}

string Thread::getName()
{
    return name;
}

int Thread::wait()
{
    int status = 0;
    if (running && !detached)
    {
        SDL_WaitThread( thread, &status );
        running = false;
    }
    return status;
}

/*
void Thread::detach()
{
    if (running && !detached)
    {
        SDL_DetachThread( thread );
        detached = true;
    }
}

bool Thread::isDetached()
{
    return detached;
}
*/

bool Thread::isRunning()
{
    return running;
}

} // namespace meh
