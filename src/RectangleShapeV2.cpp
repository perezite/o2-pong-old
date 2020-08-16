#include "RectangleShapeV2.h"

namespace o2
{
	namespace v2
	{
		RectangleShape::RectangleShape(const v1::Vector2f& size)
			: ConvexShape(4)
		{
			v1::Vector2f halfSize = .5f * size;
			getVertex(0).position = v1::Vector2f(-halfSize.x, -halfSize.y);
			getVertex(1).position = v1::Vector2f( halfSize.x, -halfSize.y);
			getVertex(2).position = v1::Vector2f( halfSize.x,  halfSize.y);
			getVertex(3).position = v1::Vector2f(-halfSize.x,  halfSize.y);
		}
	}
}
