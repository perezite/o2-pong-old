#pragma once

#include "Vector2V1.h"
#include "ColorV1.h"

namespace o2
{
	namespace v1
	{
		struct Vertex
		{
			Vector2f _position;

			Color _color;

			Vertex(const Vector2f& position = Vector2f(0, 0), const Color& color = Color(0, 0, 0, 1))
				: _position(position), _color(color)
			{ }
		};
	}
}