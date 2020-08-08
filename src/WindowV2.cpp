#include "WindowV2.h"
#include "ErrorV1.h"
#include "SDLV1.h"
#include "GLV1.h"

namespace o2
{
	namespace v2
	{
		bool Window::_hasInstance = false;

		Window::Window(const v1::Vector2i& size, const std::string& title)
			: _isOpen(true), _size(size), _title(title)
		{
			v1::SDL::init();
			_sdlWindow = v1::SDL::createWindow(size, title);
			_windowId = v1::sdlCheck(SDL_GetWindowID(_sdlWindow));
			_glContext = v1::SDL::createGLContext(_sdlWindow);
			v1::GL::init();
			_hasInstance = true;
			_renderer = new v1::Renderer();
		}

		Window::~Window()
		{
			delete _renderer;
			_hasInstance = false;
			SDL_GL_DeleteContext(_glContext);
			SDL_DestroyWindow(_sdlWindow);
			v1::SDL::quit();
		}

		void Window::clear(v1::Color color)
		{
			GL_CHECK(glClearColor(color.r, color.g, color.b, color.a));
			GL_CHECK(glClear(GL_COLOR_BUFFER_BIT));
		}

		void Window::draw(const std::vector<v1::Vertex>& vertices, v1::PrimitiveType primitiveType)
		{
			_renderer->draw(vertices, primitiveType);
		}

		void Window::display()
		{
			SDL_GL_SwapWindow(_sdlWindow);
		}
	}
}

