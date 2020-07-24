#pragma once

#include "Vector2V1.h"

#include <string>

namespace o2
{
	namespace v1 
	{
		class Window
		{
			Vector2i _size;

			std::string _title;

		public:
			Window(const Vector2i& size, const std::string& title);

			Window(int w, int h, const std::string& title) : Window(Vector2i(w, h), title)
			{ }

			bool isOpen();

			void update();
		};
	}
}

