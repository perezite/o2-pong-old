#pragma once

#include <SDL2/SDL.h>

namespace o2
{
	namespace v1
	{
		inline void sdlCheck(int resultCode)
		{
			if (resultCode < 0) 
				error(SDL_GetError());
		}

		inline void sdlCheck(void* result)
		{
			if (result == NULL)
				error(SDL_GetError());
		}
	}
}