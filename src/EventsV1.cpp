#include "EventsV1.h"
#include "STLV1.h"

#include <SDL2/SDL.h>

namespace o2
{
	namespace v1
	{
		std::vector<Uint32> Events::_closeEvents;


		void Events::clear()
		{
			_closeEvents.clear();
		}

		void Events::update()
		{
			clear();
			
			SDL_Event sdlEvent;
			while (SDL_PollEvent(&sdlEvent)) 
			{
				if (sdlEvent.type == SDL_WINDOWEVENT)
				{
					if (sdlEvent.window.event == SDL_WINDOWEVENT_CLOSE)
						_closeEvents.push_back(sdlEvent.window.windowID);
				}
			}
		}

		bool Events::hasSdlCloseEvent(Uint32 windowId)
		{
			return stl::find_any(_closeEvents, windowId);
		}
	}
}