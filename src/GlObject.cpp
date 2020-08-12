#include "GLObject.h"
#include "SDLV1.h"

#include <iostream>

using namespace std;

namespace o2
{
	namespace v1
	{
		GLObject::GLObject()
		{
			if (!SDL::hasActiveGlContext())
				error() << "Trying to create an object which requires an active OpenGL context, but no such cnotext present" << endl;
		}
	}
}