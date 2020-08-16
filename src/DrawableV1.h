#pragma once

#include "WindowV2.h"
#include "DrawStatesV1.h"

namespace o2
{
	namespace v1
	{
		class Drawable
		{
		public:
			virtual void draw(v2::Window& window, DrawStates states) = 0;
		};
	}
}