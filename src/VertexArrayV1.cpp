#include "VertexArrayV1.h"

namespace o2
{
	namespace v1
	{
		void VertexArray::draw(v2::Window & window)
		{
			window.draw(_vertices, _primitiveType);
		}
	}
}