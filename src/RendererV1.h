#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"

#include <vector>

namespace o2
{
	namespace v1
	{
		class Renderer
		{
		protected:
			void drawVertices(const std::vector<Vertex>& vertices, PrimitiveType primitiveType);

		public:
			void draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType);
		};
	}
}