#include "VideoV1.h"
#include "ErrorV1.h"

#include <SDL2/SDL.h>

namespace o2
{
	namespace v1
	{
		void Video::ensureInit()
		{
			if (SDL_Init(SDL_INIT_VIDEO) < 0) error(SDL_GetError());
		}
	}
}

