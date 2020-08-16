#pragma once

#include "WindowV3.h"

#include <SDL2/SDL.h>

#include <vector>

namespace o2
{
	namespace v3
	{
		class Events
		{
			static std::vector<Uint32> _closeEvents;

		protected:
			static void clear();

		public:
			static void update();

			static bool hasCloseRequest(const v3::Window& window);
		};
	}
}