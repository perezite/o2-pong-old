#pragma once

#include "VertexV1.h"
#include "PrimitiveTypeV1.h"
#include "ShaderV3.h"
#include "DrawStatesV1.h"

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
			void ensureDefaultShader();

			v3::Shader* getDefaultShader();

		public:
			void draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType, const DrawStates& drawStates = DrawStates());
		};
	}
}