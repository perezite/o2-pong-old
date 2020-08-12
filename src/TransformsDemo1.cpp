#include "TransformsDemo1.h"
#include "WindowV1.h"
#include "WindowV2.h"
#include "RectangleShapeV1.h"
#include "EventsV2.h"

using namespace std;
using namespace o2;

namespace transformsDemo1
{
	void demo0()
	{
		v2::Window window(v1::Vector2i(400, 400), "Pong");

		v1::RectangleShape rectangle(1);

		// rectangle.setPosition(-.5f);

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();
			rectangle.draw(window);
			window.display();
		}
	}
    
    void run()
    {
        demo0();
    }
}