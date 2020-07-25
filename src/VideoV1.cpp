#include "VideoV1.h"
#include "ErrorV1.h"
#include "SDLV1.h"
#include "GLV1.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace 
{
	using namespace o2::v1;

	inline void setGlAttribute(SDL_GLattr attribute, int value) 
	{
		sdlCheck(SDL_GL_SetAttribute(attribute, value));
	}
}

namespace o2
{
	namespace v1
	{
		void Video::init()
		{
			sdlCheck(SDL_Init(SDL_INIT_VIDEO));

			int flags = IMG_INIT_PNG && IMG_INIT_JPG;
			int imgResult = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & flags;
			if (imgResult != flags) error(IMG_GetError());

			#ifdef WIN32
				setGlAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
				setGlAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
				setGlAttribute(SDL_GL_DOUBLEBUFFER, 1);
				setGlAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
				setGlAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			#elif defined(__ANDROID__)
				setGlAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
				setGlAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
				setGlAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
				setGlAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
			#endif		
		}

		Vector2i Video::getDisplaySize()
		{
			SDL_DisplayMode displayMode;
			sdlCheck(SDL_GetDisplayMode(0, 0, &displayMode));
			return Vector2i(displayMode.w, displayMode.h);
		}

		#ifdef WIN32
			void Video::initGlew()
			{
			// 	glewCheck(glewInit());
			}
		#endif		
	}
}

