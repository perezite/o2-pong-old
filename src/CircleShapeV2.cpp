#include "CircleShapeV2.h"
#include "Vector2V1.h"
#include "MathV1.h"

namespace o2
{
	namespace v2
	{
		CircleShape::CircleShape(size_t numVertices)
			: ConvexShape(numVertices)
		{
			float deltaAngle = 2 * v1::math::Pi / float(numVertices);

			for (size_t i = 0; i < numVertices; i++)
			{
				float angle = v1::math::Pi / 2 + i * deltaAngle;
				getVertex(i).position = v1::Vector2f(cosf(angle), sinf(angle));
			}
		}
	}
}

