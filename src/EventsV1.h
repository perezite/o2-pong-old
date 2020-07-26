#pragma once

#include <SDL2/SDL.h>

#include <vector>

namespace o2
{
	namespace v1
	{
		class Events
		{
			static std::vector<Uint32> _closeEvents;

		protected:
			static void clear();

		public:
			static void update();

			static bool hasSdlCloseEvent(Uint32 windowId);
		};
	}
}