#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace o2
{
	namespace v1 
	{
		void error(const std::string& os);

		void error(std::ostringstream& os);
	}
}
