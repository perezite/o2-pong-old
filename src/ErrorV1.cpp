#include "ErrorV1.h"

#include <SDL2/SDL.h>

#include <sstream>
#include <string>
using namespace std;

namespace
{
	#ifdef _MSC_VER
		void debug(const string& message) {
			int result;

			const SDL_MessageBoxButtonData buttons[] =
			{
				{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Quit" },
				{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Debug" }
			};

			const SDL_MessageBoxData messageboxdata =
			{
				SDL_MESSAGEBOX_ERROR, NULL, "A problem occured",
				message.c_str(), SDL_arraysize(buttons), buttons, NULL
			};

			SDL_ShowMessageBox(&messageboxdata, &result);

			if (result == 1)
				__debugbreak();
		}
	#endif
}

namespace o2
{
	namespace v1
	{
		void error(const string& message) {
			#if defined(_MSC_VER) && defined(_DEBUG)
				debug(message);
			#else
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "A problem occured", message.c_str(), NULL);
			#endif

			exit(0);
		}
	}
}
