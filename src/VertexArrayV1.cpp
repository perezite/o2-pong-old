#include "VertexArrayV1.h"

namespace o2
{
	namespace v1
	{
		void VertexArray::draw(v2::Window& window, DrawStates drawStates)
		{
			window.draw(_vertices, _primitiveType);
		}
	}
}