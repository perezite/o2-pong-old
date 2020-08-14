#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "ShaderV3.h"

#include <vector>

namespace o2
{
	namespace v2
	{
		class Window;
	}
	
	namespace v1
	{
		class Renderer
		{
			v3::Shader _defaultShader;

		protected:
			v3::Shader* ensureDefaultShader();

		public:
			void draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType, v3::Shader* shader = NULL);
		};
	}
}