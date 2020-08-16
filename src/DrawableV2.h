#pragma once

#include "WindowV3.h"
#include "DrawStatesV1.h"

namespace o2
{
	namespace v2
	{
		class Drawable
		{
		public:
			virtual void draw(v3::Window& window, v1::DrawStates drawStates) = 0;
		};
	}
}