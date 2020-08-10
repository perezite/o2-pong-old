#include "ShapesDemo1.h"

#include "WindowV2.h"
#include "EventsV2.h"
#include "Math.h"
#include "ConvexShapeV1.h"

#include <stdlib.h>

using namespace o2;

namespace shapesDemo1
{
	void demo0()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v1::ConvexShape triangle(3);

		triangle[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		triangle[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		triangle[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			triangle.draw(window);

			window.display();
		}
	}

	void demo1()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v1::ConvexShape triangle(3);

		triangle[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		triangle[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		triangle[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		triangle.setColor(v1::Color(0, 1, 0, 1));

		srand(42);
		
		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();
			
			v1::Color color(v1::Color(v1::math::random(), v1::math::random(), v1::math::random(), 1));
			triangle.setColor(color);

			window.clear();
			triangle.draw(window);
			window.display();
		}
	}

	void run()
	{
		demo1();
		// demo0();
	}
}
