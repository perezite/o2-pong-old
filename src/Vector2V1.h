#pragma once

namespace o2
{
	namespace v1
	{
		template <class T>
		struct Vector2
		{
			T x, y;

		public:
			inline Vector2() : x(T()), y(T())
			{ }

			inline Vector2(const T& s) : x(s), y(s)
			{ }

			inline Vector2(const T& x_, const T& y_) : x(x_), y(y_)
			{ }
		};

		template <class T> 
		inline Vector2<T> operator*(const T& s, const Vector2<T>& v)
		{
			return Vector2<T>(s * v.x, s * v.y);
		}

		typedef Vector2<int> Vector2i;
		typedef Vector2<float> Vector2f;
	}
}