#include "WindowV1.h"
#include "ErrorV1.h"
#include "SDLV1.h"
#include "GLV1.h"

namespace o2
{
	namespace v1
	{
		Window::Window(const Vector2i& size, const std::string& title)
			: _isOpen(true), _size(size), _title(title)
		{
			SDL::init();
			_sdlWindow = SDL::createWindow(size, title);
			SDL::createGlContext(_sdlWindow);
			GL::init();
		}

		Window::~Window()
		{
			SDL_DestroyWindow(_sdlWindow);
			SDL::quit();
		}

		bool Window::isOpen()
		{
			return _isOpen;
		}
			
		void Window::update()
		{
			SDL_Event sdlEvent;
			
			while (SDL_PollEvent(&sdlEvent)) {
				if (sdlEvent.type == SDL_WINDOWEVENT)
				{
					if (sdlEvent.window.windowID == SDL_GetWindowID(_sdlWindow))
					{
						if (sdlEvent.window.event == SDL_WINDOWEVENT_CLOSE)
						{
							_isOpen = false;
						}
					}
				}
			}

		}

		void Window::display()
		{
			SDL_GL_SwapWindow(_sdlWindow);
		}
	}
}

