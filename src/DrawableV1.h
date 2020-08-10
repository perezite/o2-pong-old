#pragma once

#include "WindowV2.h"

namespace o2
{
	namespace v1
	{
		class Drawable
		{
		public:
			virtual void draw(v2::Window& window) = 0;
		};
	}
}