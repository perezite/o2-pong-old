#include "ConvexShapeV1.h"

namespace o2
{
	namespace v1
	{
		void ConvexShape::setColor(const v1::Color& color)
		{
			for (size_t i = 0; i < _vertexArray.getVertexCount(); i++)
				_vertexArray[i].color = color;
		}

		void ConvexShape::draw(v2::Window & window)
		{
			_vertexArray.draw(window);
		}
	}
}

