#pragma once

#include "Vector2V1.h"
#include "ColorV1.h"

#include <SDL2/SDL.h>
#include <string>

namespace o2
{
	namespace v1 
	{
		// Remark: Idea for multi window event processing: https://gist.github.com/perezite/50b3f3bad7d2697cf5ce1b96b9a70307
		// Also: https://lazyfoo.net/tutorials/SDL/36_multiple_windows/index.php
		class Window
		{
			bool _isOpen;

			Vector2i _size;

			std::string _title;

			SDL_Window* _sdlWindow;

			Uint32 _windowId;

		public:
			Window(const Vector2i& size, const std::string& title);

			Window(int w, int h, const std::string& title) : Window(Vector2i(w, h), title)
			{ }

			virtual ~Window();

			bool isOpen();

			void update();

			void clear(Color color = Color(0, 0, 0, 1));

			void display();
		};
	}
}

