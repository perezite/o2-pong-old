#include "CircleShapeV1.h"
#include "Vector2V1.h"
#include "MathV1.h"

namespace o2
{
	namespace v1
	{
		CircleShape::CircleShape(size_t numVertices)
			: ConvexShape(numVertices)
		{
			float deltaAngle = 2 * math::Pi / float(numVertices);

			for (size_t i = 0; i < numVertices; i++)
			{
				float angle = math::Pi / 2 + i * deltaAngle;
				getVertex(i).position = Vector2f(cosf(angle), sinf(angle));
			}
		}
	}
}

