#pragma once 

#include "ConvexShapeV2.h"

namespace o2
{
	namespace v2
	{
		class CircleShape : public ConvexShape
		{

		public:
			CircleShape(size_t numVertices);
		};
	}
}