#pragma once

#include "ConvexShapeV1.h"
#include "Vector2V1.h"

namespace o2
{
	namespace v1 
	{
		class RectangleShape : public ConvexShape
		{
		public:
			RectangleShape(const Vector2f& size);
		};
	}
}