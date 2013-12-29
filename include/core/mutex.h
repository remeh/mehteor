#ifndef MEH_MUTEX_H
#define MEH_MUTEX_H

#include <string>
#include <SDL/SDL_thread.h>

using namespace std;

namespace meh
{

/**
 * Simple mutex class upon the SDL_mutex objects.
 *
 * @author Rémy 'remeh' MATHIEU
 */
class Mutex
{
    private:
        SDL_mutex* mutex;

    protected:
    public:
        /**
         * Default constructor.
         */
        Mutex();
        ~Mutex();

        /**
         * Locks the mutex. 
         * If the mutex is already locked, it will not return until it is unlocked.
         * @return 0 on success, or -1 on an error.
         */
        int lock();

        /**
         * Unlocks the mutex.
         * @return 0 on success, or -1 on an error. 
         */
        int unlock();

        /**
         * Returns the SDL mutex.
         * @return the SDL mutex.
         */
        SDL_mutex* getSDLMutex();
};

} // namespace meh

#endif // MEH_MUTEX_H


