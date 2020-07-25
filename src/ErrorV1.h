#pragma once

#include "ErrorV1.h"

#include <iostream>
#include <sstream>
#include <string>

namespace o2
{
	namespace v1 
	{
		void error(const std::string& os);

		class ErrorStream : public std::ostringstream
		{
		public:
			inline ErrorStream() { }

			inline ErrorStream(ErrorStream& other)
			{
				other << rdbuf();
			}

			inline virtual ~ErrorStream()
			{
				std::string errorString = str();
				if (errorString.size() > 0)
					error(errorString);
			}
		};

		inline void error(std::ostringstream& message) 
		{
			error(message.str());
		}

		inline ErrorStream error()
		{
			ErrorStream errorStream;
			return errorStream;
		}
	}
}
