#pragma once

#include "TimeV1.h"

#include <SDL2/SDL.h>

namespace o2
{
    namespace v1
    {
        class Clock
        {
            Uint32 _startTicks;

        public:
            Clock();

            void reset();

            const Time getElapsedTime();
        };
    }
}
