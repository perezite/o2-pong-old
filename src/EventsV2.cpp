#include "EventsV2.h"
#include "STLV1.h"

#include <SDL2/SDL.h>
#include "EventsV2.h"

namespace o2
{
	namespace v2
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

		bool Events::isCloseRequested(const v2::Window& window)
		{
			return v1::stl::find_any(_closeEvents, window.getSdlWindowId());
		}
	}
}