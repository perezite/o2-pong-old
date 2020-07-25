#include "GLV1.h"
#include "ErrorV1.h"


namespace
{
	using namespace o2;

	#ifdef WIN32
		void glewCheck(GLenum result)
		{
			if (result != GLEW_OK)
			{
				std::ostringstream os;
				os << glewGetErrorString(result);
				v1::error(os);
			}
		}
	#endif
}

namespace o2
{
	namespace v1
	{
		void GL::init()
		{
			#ifdef WIN32
				glewCheck(glewInit());
			#endif
		}
	}
}