#pragma once

#include <random>

namespace o2
{
	namespace v1
	{
		namespace math
		{
			inline float random()
			{
				return rand() / float(RAND_MAX);
			}

			inline float random(float min, float max)
			{
				return min + (max - min) * random();
			}
		}
	}
}