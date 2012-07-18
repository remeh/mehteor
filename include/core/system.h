#ifndef MEH_SYSTEM_H
#define MEH_SYSTEM_H

#include <cstdint>

namespace meh {

class System {
    private:
        static bool initializated;
        static bool graphics;

    protected:
    public:

        /**
         * Initialization.
         *
         * Must be called at the very beginning
         * in order to init every sub-systems (mouse, 
         * keyboard, sound, ...)
         * @param initGraphics should the graphic system be init? 
         */
        static void init(bool initGraphics = true);

        /**
         * Deinitialization.
         */
        static void deinit();

        /**
         * Returns whether the system has been correctly initializated.
         */
        static bool isInitializated();

        /**
         * Returns whether the graphics subsystem is enabled.
         */
        static bool graphicsEnabled();

        /**
         * Returns a random number between min (inlcuded) and max (excluded).
         */
        static int rnd(int min, int max);
        
        /**
         * Returns a random number between 0 (inlcuded) and max (excluded).
         */
        static int rnd(int max);

        /**
         * Returns since how many milli-seconds the app has been launched.
         */
        static uint32_t currentTime();

        /**
         * Waits for the specified number milli-seconds. This tells the
         * system to pause the current thread for the given amount of
         * time.
         */
        static void sleep(unsigned int ms);
};

} // namespace meh

#endif // MEH_SYSTEM_H
