#pragma once 

#include "WindowV2.h"
#include "VertexV1.h"
#include "ColorV1.h"
#include "DrawableV1.h"
#include "PrimitiveTypeV1.h"
#include "VertexArrayV1.h"

namespace o2
{
	namespace v1
	{
		class ConvexShape : public Drawable
		{
			VertexArray _vertexArray;

		public:
			ConvexShape(size_t numVertices)
				: _vertexArray(numVertices, PrimitiveType::TriangleFan)
			{ }

			void setColor(const v1::Color& color);

			inline v1::Vertex& getVertex(size_t index) { return _vertexArray[index]; }

			inline v1::Vertex& operator[](size_t index) { return getVertex(index); }

			void draw(v2::Window& window);
		};
	}
}