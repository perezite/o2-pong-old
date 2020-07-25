#pragma once

#include "ErrorV1.h"

#ifdef WIN32
	#include <gl/glew.h>
	#include <SDL2/SDL_opengl.h>
	#include <gl/glu.h>
#else
	#include <GLES2/gl2.h>	
	#include <GLES2/gl2ext.h>
#endif 

#include <sstream>
using namespace std;

namespace o2
{
	namespace v1
	{
		#ifdef WIN32
		void glewCheck(GLenum result) 
		{
			if (result != GLEW_OK)
			{
				std::ostringstream os;
				os << glewGetErrorString(result);
				error(os);
			}
		}
		#endif	
	}
}