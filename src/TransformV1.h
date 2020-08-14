#pragma once

#include "Vector2V1.h"

#include <vector>

namespace o2
{
	namespace v1
	{
		class Transform
		{
			std::vector<float> _matrix;

		public:
			Transform(	
				float a00 = 1, float a01 = 0, float a02 = 0,
				float a10 = 0, float a11 = 1, float a12 = 0,
				float a20 = 0, float a21 = 0, float a22 = 1);

			inline const std::vector<float> getMatrix() const { return _matrix; }

			const Transform& apply(const Transform& transform);

			const Transform& translate(const Vector2f& offset);

			const inline Transform& translate(float x, float y) { return translate(v1::Vector2f(x, y)); }

			const Transform& rotate(float degrees);
		};
	}
}