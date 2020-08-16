#include "VertexArrayV2.h"

namespace o2
{
	namespace v2
	{
		void VertexArray::draw(v3::Window& window, v1::DrawStates drawStates)
		{
			window.draw(_vertices, _primitiveType, drawStates);
		}
	}
}