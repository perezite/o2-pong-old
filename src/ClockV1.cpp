#include "ClockV1.h"

namespace o2
{ 
    namespace v1
    {
        Clock::Clock()
        {
            reset();
        }

        void Clock::reset()
        {
            _startTicks = SDL_GetTicks();
        }

        const Time Clock::getElapsedTime()
        {
            auto test = SDL_GetTicks();
            return Time().fromMilliseconds(SDL_GetTicks() - _startTicks);
        }        
    }
}
