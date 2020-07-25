#pragma once

//#include "GLV1.h"
#include "Vector2V1.h"

namespace o2
{
	namespace v1 
	{
		class Video 
		{
		public:
			static void init();

			static Vector2i getDisplaySize();

			#ifdef WIN32
				static void initGlew();
			#endif			
		};
	}
}