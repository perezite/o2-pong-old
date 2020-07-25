#include "WindowV1.h"
#include "ErrorV1.h"
#include "SDLV1.h"
#include "GLV1.h"

namespace o2
{
	namespace v1
	{
		Window::Window(const Vector2i& size, const std::string& title)
			: _size(size), _title(title)
		{
			SDL::init();
			SDL_Window* sdlWindow = SDL::createWindow(size, title);
			SDL::createGlContext(sdlWindow);
			GL::init();
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

