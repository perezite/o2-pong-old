#pragma once

#include "ErrorV1.h"
#include "Vector2V1.h"

#include <SDL2/SDL.h>

namespace o2
{
	namespace v1
	{
		class SDL 
		{
		public: 
			static void init();

			static SDL_Window* createWindow(const v1::Vector2i& size, const std::string& title);

			static SDL_GLContext createGlContext(SDL_Window* sdlWindow);

			static void quit();
		};

		inline int sdlCheck(int resultCode)
		{
			if (resultCode < 0)
				error(SDL_GetError());

			return resultCode;
		}

		inline void* sdlCheck(void* result)
		{
			if (result == NULL)
				error(SDL_GetError());

			return result;
		}
	}
}