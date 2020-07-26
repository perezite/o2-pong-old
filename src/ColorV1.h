#pragma once

namespace o2
{
	namespace v1
	{
		typedef unsigned char uchar;

		struct Color
		{
			float r, g, b, a;

			Color(float r_ = 1, float g_ = 1, float b_ = 1, float a_ = 1)
				: r(r_), g(g_), b(b_), a(a_)
			{ }

			static Color fromRGBA(uchar r = 0, uchar g = 0, uchar b = 0, uchar a = 255)
			{
				return Color(r / 255.f, g / 255.f, b / 255.f, a / 255.f);
			}
		};
	}
}