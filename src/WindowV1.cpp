#include "WindowV1.h"
#include "ErrorV1.h"
#include "VideoV1.h"
#include "SDLV1.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <sstream>

using namespace std;

namespace o2
{
	namespace v1
	{
		Window::Window(const Vector2i& size, const std::string& title)
			: _size(size), _title(title)
		{
			Video::ensureInit();

			SDL_Window* sdlWindow = 
				SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
					size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
			sdlCheck(sdlWindow);
			SDL_GLContext glContext = SDL_GL_CreateContext(sdlWindow);
			sdlCheck(glContext);

			#ifdef WIN32
				//Video::ensureGlew();
			#endif
		}

		bool Window::isOpen()
		{
			return false;
		}

		void Window::update()
		{
		}
	}
}

