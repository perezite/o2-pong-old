#include "ConvexShapeV2.h"

namespace o2
{
    namespace v2
    {
        void ConvexShape::setColor(const v1::Color& color)
        {
            for (size_t i = 0; i < _vertexArray.getVertexCount(); i++)
                _vertexArray[i].color = color;
        }

        void ConvexShape::draw(v3::Window& window, v1::DrawStates drawStates)
        {
            drawStates.transform *= getTransform();
            _vertexArray.draw(window, drawStates);
        }
    }
}

