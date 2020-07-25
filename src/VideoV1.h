#pragma once

//#include "GLV1.h"

namespace o2
{
	namespace v1 
	{
		class Video 
		{
		public:
			static void ensureInit();

			#ifdef WIN32
				static void ensureGlew();
			#endif			
		};
	}
}