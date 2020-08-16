#pragma once 

#include "WindowV2.h"
#include "VertexV1.h"
#include "ColorV1.h"
#include "DrawableV2.h"
#include "PrimitiveTypeV1.h"
#include "VertexArrayV2.h"
#include "TransformableV1.h"

namespace o2
{
	namespace v2
	{
		class ConvexShape : public v2::Drawable, public v1::Transformable
		{
			VertexArray _vertexArray;

		public:
			ConvexShape(size_t numVertices)
				: _vertexArray(numVertices, v1::PrimitiveType::TriangleFan)
			{ }

			void setColor(const v1::Color& color);

			inline v1::Vertex& getVertex(size_t index) { return _vertexArray[index]; }

			inline v2::VertexArray& getVertexArray() { return _vertexArray; }

			inline v1::Vertex& operator[](size_t index) { return getVertex(index); }

			void draw(v3::Window& window, v1::DrawStates drawStates = v1::DrawStates());
		};
	}
}