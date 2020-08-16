#pragma once

#include "DrawableV2.h"
#include "PrimitiveTypeV1.h"
#include "VertexV1.h"
#include "WindowV3.h"

#include <vector>

namespace o2
{
	namespace v2
	{
		class VertexArray : public v2::Drawable
		{
			std::vector<v1::Vertex> _vertices;

			v1::PrimitiveType _primitiveType;

		public:
			VertexArray(size_t numVertices, v1::PrimitiveType primitiveType)
				: _vertices(numVertices), _primitiveType(primitiveType)
			{ }

			inline std::vector<v1::Vertex>& getVertices() { return _vertices; }

			inline size_t getVertexCount() const { return _vertices.size(); }

			inline v1::PrimitiveType getPrimitiveType() const { return _primitiveType; }

			inline v1::Vertex& operator[] (size_t index) { return _vertices[index]; }

			virtual void draw(v3::Window& window, v1::DrawStates drawStates = v1::DrawStates());
		};
	}
}