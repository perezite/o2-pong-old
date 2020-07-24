#include "WindowV1.h"
#include "ErrorV1.h"
#include "VideoV1.h"

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

