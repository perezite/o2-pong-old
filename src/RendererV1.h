#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "ShaderV3.h"

#include <vector>

namespace o2
{
	namespace v1
	{
		class Renderer
		{
			v3::Shader _defaultShader;

		protected:
			void ensureDefaultShader();

		public:
			void draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType, v3::Shader* shader = NULL);
		};
	}
}