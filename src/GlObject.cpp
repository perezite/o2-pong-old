#include "GlObject.h"
#include "SDLV1.h"

#include <iostream>

using namespace std;

namespace o2
{
	namespace v1
	{
		GlObject::GlObject()
		{
			if (!SDL::hasActiveGlContext())
				error() << "Trying to create an object which requires an active OpenGL context, but no such context is present" << endl;
		}
	}
}