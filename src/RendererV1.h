#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "ShaderV2.h"

#include <vector>

namespace o2
{
	namespace v1
	{
		class Renderer
		{
			v2::Shader _defaultShader;

		public:
			void draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType);
		};
	}
}