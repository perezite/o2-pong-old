#pragma once

#include "WindowV2.h"

#include <SDL2/SDL.h>

#include <vector>

namespace o2
{
	namespace v2
	{
		class Events
		{
			static std::vector<Uint32> _closeEvents;

		protected:
			static void clear();

		public:
			static void update();

			static bool isCloseRequested(const v2::Window& window);
		};
	}
}