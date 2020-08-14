#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "ShaderV4.h"
#include "DrawStatesV1.h"

#include <vector>

namespace o2
{
	namespace v2
	{
		class Window;
	}
	
	namespace v2
	{
		class Renderer
		{
			v4::Shader _defaultShader;

		protected:
			v4::Shader* ensureDefaultShader();

		public:
			void draw(const std::vector<v1::Vertex>& vertices, v1::PrimitiveType primitiveType, const v1::DrawStates& drawStates = v1::DrawStates());
		};
	}
}