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
				inline static void ensureGlew();
			#endif			
		};
	}
}