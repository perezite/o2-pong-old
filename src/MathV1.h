#pragma once

#include <random>
#include <math.h>

#define _USE_MATH_DEFINES

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

			const float Pi = (float)M_PI;

			const float ToRadian = Pi / 180;

            const float ToDegrees = 180 / Pi;
		}
	}
}