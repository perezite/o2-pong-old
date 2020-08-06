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

#if defined(_DEBUG) && !defined(GL_DISABLE_CHECKS)
	#define GL_CHECK(cmd) do { cmd; o2::v1::priv::glCheck(#cmd, __FILE__, __LINE__); } while (false)
#else
	#define GL_CHECK(cmd) cmd
#endif

namespace o2
{
	namespace v1
	{
		class GL
		{
		public:
			static void init();
			
			static std::string getErrorDescription(GLenum error);
		};

		namespace priv
		{
			void glCheck(const char* command, const char* file, unsigned int line);
		}
	}
}