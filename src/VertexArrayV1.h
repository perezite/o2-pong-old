#pragma once

#include "DrawableV1.h"
#include "PrimitiveTypeV1.h"
#include "VertexV1.h"
#include "WindowV2.h"

#include <vector>

namespace o2
{
	namespace v1
	{
		class VertexArray : public Drawable
		{
			std::vector<Vertex> _vertices;

			PrimitiveType _primitiveType;

		public:
			VertexArray(size_t numVertices, v1::PrimitiveType primitiveType)
				: _vertices(numVertices), _primitiveType(primitiveType)
			{ }

			inline Vertex& operator[] (size_t index) { return _vertices[index]; }

			inline size_t getVertexCount() const { return _vertices.size(); }

			virtual void draw(v2::Window& window);
		};
	}
}