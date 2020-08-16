#pragma once

#include "ConvexShapeV2.h"
#include "Vector2V1.h"

namespace o2
{
	namespace v2
	{
		class RectangleShape : public ConvexShape
		{
		public:
			RectangleShape(const v1::Vector2f& size = v1::Vector2f(1, 1));

            inline RectangleShape(float x, float y)
                : RectangleShape(v1::Vector2f(x, y))
            { }
		};
	}
}