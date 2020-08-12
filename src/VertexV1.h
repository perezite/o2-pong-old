#pragma once

#include "Vector2V1.h"
#include "ColorV1.h"

namespace o2
{
	namespace v1
	{
		struct Vertex
		{
			Vector2f position;

			Color color;

			Vertex(const Vector2f& position_ = Vector2f(0, 0), const Color& color_ = Color(1, 1, 1, 1))
				: position(position_), color(color_)
			{ }
		};
	}
}