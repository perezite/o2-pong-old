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
			RectangleShape(const Vector2f& size = Vector2f(1, 1));

            inline RectangleShape(float x, float y)
                : RectangleShape(Vector2f(x, y))
            { }
		};
	}
}