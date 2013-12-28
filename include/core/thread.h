#ifndef MEH_THREAD_H
#define MEH_THREAD_H

#include <string>
#include <SDL/SDL_thread.h>

using namespace std;

namespace meh
{

class Thread
{
    private:
        SDL_Thread* thread;

        string name;

        bool running;

        // TODO when porting to SDL 2.0
        bool detached;

    protected:
    public:
        /**
         * Default constructor.
         */
        Thread(string name, int func(void*), void* args);
        ~Thread();

        SDL_Thread* getSDLThread();

        string getName();

        bool isRunning();

        // TODO when porting to SDL 2.0
        //bool isDetached();

        int wait();

        // TODO when porting to SDL 2.0
        // void detach();
};

} // namespace meh

#endif // MEH_THREAD_H

