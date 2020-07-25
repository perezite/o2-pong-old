#include "WindowV1.h"
#include "ErrorV1.h"
#include "VideoV1.h"
#include "SDLV1.h"
#include "GLV1.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <sstream>

using namespace std;

namespace 
{
	using namespace o2;

	SDL_Window* createSdlWindow(const v1::Vector2i& size, const std::string& title)
	{
		#ifdef WIN32
			return SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		#elif defined(__ANDROID__)
			v1::Vector2i displaySize = v1::Video::getDisplaySize();
			return SDL_CreateWindow(title.c_str(), 0, 0, size.x, size.y,
				SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
		#endif
	}
}

namespace o2
{
	namespace v1
	{
		Window::Window(const Vector2i& size, const std::string& title)
			: _size(size), _title(title)
		{
			SDL::init();
			SDL_Window* sdlWindow = SDL::createWindow(size, title);
			SDL_GLContext glContext = SDL::createGlContext(sdlWindow);
			GL::init();


			/*
			SDL::init();
			SDL_Window* sdlWindow = SDL::createWindow(size, title);
			SDL_GLContext glContext = SDL::createGlContext(sdlWindow);
			GL::init();
			*/

			//Video::init();
			//
			//SDL_Window* sdlWindow = createSdlWindow(size, title);
			//sdlCheck(sdlWindow);
			//sdlCheck(SDL_GL_CreateContext(sdlWindow));



			//#ifdef WIN32
			//	Video::initGlew();
			//#endif
		}

		bool Window::isOpen()
		{
			return true;
		}

		void Window::update()
		{
		}
	}
}

