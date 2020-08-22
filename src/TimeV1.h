#pragma once

#include <SDL2/SDL.h>

namespace o2
{
    namespace v1
    {
        class Time
        {
            Uint32 _ticks;

        public:
            inline Time& fromMilliseconds(unsigned int milliseconds) 
            {
                _ticks = milliseconds; 
                return *this; 
            }

            inline float asSeconds() const { return _ticks / 1000.0f; }
        };
    }
}