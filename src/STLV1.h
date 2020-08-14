#pragma once

#include <algorithm>

using namespace std;

namespace o2
{
	namespace v1
	{
		namespace stl
		{
			template <class Container, class T>
			inline static bool has_any(Container container, T val)
			{
				return find(container.begin(), container.end(), val) != container.end();
			}
		}
	}
}