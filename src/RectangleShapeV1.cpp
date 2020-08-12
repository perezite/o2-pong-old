#include "RectangleShapeV1.h"

namespace o2
{
	namespace v1
	{
		RectangleShape::RectangleShape(const Vector2f& size)
			: ConvexShape(4)
		{
			Vector2f halfSize = .5f * size;
			getVertex(0).position = Vector2f(-halfSize.x, -halfSize.y);
			getVertex(1).position = Vector2f( halfSize.x, -halfSize.y);
			getVertex(2).position = Vector2f( halfSize.x,  halfSize.y);
			getVertex(3).position = Vector2f(-halfSize.x,  halfSize.y);
		}
	}
}
