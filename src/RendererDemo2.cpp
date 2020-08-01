#include "WindowDemo1.h"
#include "WindowV2.h"
#include "ShaderV1.h"
#include "EventsV2.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace o2;

namespace rendererDemo2
{	
	void demo0()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.display();
		}
	}

	void demo1()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v1::Renderer renderer;
		vector<v1::Vertex> vertices(3);
		v1::Color color = v1::Color::fromRGBA(100, 100, 0, 255);

		vertices[0] = v1::Vertex(v1::Vector2f( -.5f, -.5f), color);
		vertices[1] = v1::Vertex(v1::Vector2f(  .5f, -.5f), color);
		vertices[2] = v1::Vertex(v1::Vector2f(    0,  .5f), color);

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			renderer.draw(vertices, v1::PrimitiveType::Triangles);

			window.display();
		}
	}

    void run()
    {
		demo1();
        //demo0();
    }
}