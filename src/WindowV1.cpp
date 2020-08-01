#include "WindowV1.h"
#include "ErrorV1.h"
#include "EventsV1.h"
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
			_windowId = sdlCheck(SDL_GetWindowID(_sdlWindow));
			SDL::createGLContext(_sdlWindow);
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
			Events::update();
			
			if (Events::hasSdlCloseEvent(_windowId))
				_isOpen = false;
		}

		void Window::clear(Color color)
		{
			GL_CHECK(glClearColor(color.r, color.g, color.b, color.a));
			GL_CHECK(glClear(GL_COLOR_BUFFER_BIT));
		}

		void Window::draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType)
		{
			_renderer.draw(vertices, primitiveType);
		}

		void Window::display()
		{
			SDL_GL_SwapWindow(_sdlWindow);
		}
	}
}

