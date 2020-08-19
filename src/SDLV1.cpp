#include "SDLV1.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace
{
	using namespace o2;

	inline void setGlAttribute(SDL_GLattr attribute, int value)
	{
		v1::sdlCheck(SDL_GL_SetAttribute(attribute, value));
	}

	v1::Vector2i getDisplaySize()
	{
		SDL_DisplayMode displayMode;
		v1::sdlCheck(SDL_GetDisplayMode(0, 0, &displayMode));
		return v1::Vector2i(displayMode.w, displayMode.h);
	}
}

namespace o2
{
	namespace v1
	{
		void SDL::init()
		{
			sdlCheck(SDL_Init(SDL_INIT_VIDEO));

			int flags = IMG_INIT_PNG && IMG_INIT_JPG;
			int imgResult = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & flags;
			if (imgResult != flags) error(IMG_GetError());

			#ifdef WIN32
				setGlAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
				setGlAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
				setGlAttribute(SDL_GL_DOUBLEBUFFER, 1);
				setGlAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
				setGlAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			#elif defined(__ANDROID__)
				setGlAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
				setGlAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
				setGlAttribute(SDL_GL_DOUBLEBUFFER, 1);
				setGlAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
				setGlAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
			#endif	
		}

		SDL_Window * SDL::createWindow(const v1::Vector2i & size, const std::string & title)
		{
			#ifdef WIN32
				return SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
			#elif defined(__ANDROID__)
				v1::Vector2i displaySize = getDisplaySize();
				return SDL_CreateWindow(title.c_str(), 0, 0, displaySize.x, displaySize.y,
					SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
			#endif
		}

		SDL_GLContext SDL::createGLContext(SDL_Window* sdlWindow)
		{
			return sdlCheck(SDL_GL_CreateContext(sdlWindow));
		}

		void SDL::quit()
		{
			IMG_Quit();
			SDL_Quit();
		}

		bool SDL::hasActiveGlContext()
		{
			SDL_GLContext context = SDL_GL_GetCurrentContext();
			return context != NULL;
		}
	}
}