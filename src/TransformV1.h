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
            Transform(const Vector2f& position = Vector2f(0), float degrees = 0, const Vector2f& scale = Vector2f(1));

			Transform(	
				float a00, float a01, float a02,
				float a10, float a11, float a12,
				float a20, float a21, float a22);

			inline const std::vector<float> getMatrix() const { return _matrix; }

			const Transform& apply(const Transform& transform);

			const Transform& translate(const Vector2f& offset);

            inline const Transform& translate(float x, float y) { return translate(v1::Vector2f(x, y)); }

            const Transform& rotate(float degrees);

            const Transform& scale(const Vector2f& scaling);

            inline const Transform& scale(float x, float y) { return scale(v1::Vector2f(x, y)); }
		};

        Transform operator*(Transform& left, const Transform& right);

        Transform& operator*=(Transform& left, const Transform& right);
	}
}