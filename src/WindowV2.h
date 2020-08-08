#pragma once

#include "Vector2V1.h"
#include "ColorV1.h"
#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "RendererV1.h"

#include <SDL2/SDL.h>
#include <string>
#include <vector>

namespace o2
{
	namespace v2
	{
		// Remark: Idea for multi window event processing: https://gist.github.com/perezite/50b3f3bad7d2697cf5ce1b96b9a70307
		// Also: https://lazyfoo.net/tutorials/SDL/36_multiple_windows/index.php
		class Window
		{
			static bool _hasInstance;

			bool _isOpen;

			v1::Vector2i _size;

			std::string _title;

			SDL_Window* _sdlWindow;

			Uint32 _windowId;

			SDL_GLContext _glContext;

			v1::Renderer* _renderer;

		public:
			inline static bool hasInstance() { return _hasInstance; }

			Window(const v1::Vector2i& size, const std::string& title);

			Window(int w, int h, const std::string& title) : Window(v1::Vector2i(w, h), title)
			{ }

			virtual ~Window();

			inline bool isOpen() const { return _isOpen; }

			inline Uint32 getSdlWindowId() const { return _windowId; }

			inline void close() { _isOpen = false; }

			void clear(v1::Color color = v1::Color(0, 0, 0, 1));

			void draw(const std::vector<v1::Vertex>& vertices, v1::PrimitiveType primitiveType = v1::PrimitiveType::Triangles);

			void display();
		};
	}
}

