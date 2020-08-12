#pragma once 

#include "ConvexShapeV1.h"

namespace o2
{
	namespace v1
	{
		class CircleShape : public ConvexShape
		{

		public:
			CircleShape(size_t numVertices);
		};
	}
}