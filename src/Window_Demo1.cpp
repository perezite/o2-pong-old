#include "Window_Demo1.h"
#include "WindowV1.h"
#include "ColorV1.h"
#include <iostream>

using namespace std;
using namespace o2;

namespace windowDemo1
{
    void demo0()
    {
        v1::Window window(v1::Vector2i(600, 400), "Pong");

        while (window.isOpen())
        {
            window.update();
			window.clear(v1::Color::fromRGBA(0, 255, 0, 255));
            window.display();
        }
    }

	//void demo2()
	//{
	/*v1::Window window(v1::Vector2i(600, 400), "Pong");
	v1::PolygonShape shape;
	shape.setPointCount(5);
	shape[0].position = Vector2i(   0, -200);
	shape[1].position = Vector2i( 200,    0);
	shape[2].position = Vector2i( 100,  200);
	shape[3].position = Vector2i(-100,  200);
	shape[4].position = Vector2i(-200,    0);

	while (window.isOpen())
	{
		window.update();
		window.draw(shape);
		window.display();
	}*/
	//}

	void demo1()
	{
		/*v1::Window window(v1::Vector2i(600, 400), "Pong");
		Color color = Color::fromRgb(0, 255, 0);
		vector<v1::Vertex2i> vertices;
		vertices[0] = Vertex(Vector2i(   0, -200), color);		// 0
		vertices[1] = Vertex(Vector2i( 200,    0), color);		// 1
		vertices[2] = Vertex(Vector2i(-200,    0), color);		// 4
		vertices[3] = Vertex(Vector2i( 100,  200), color);		// 2
		vertices[4] = Vertex(Vector2i(-100,  200), color);		// 3

		while (window.isOpen())
		{
			window.update();
			window.draw(vertices, v1::PrimitiveType::TriangleStrip);
			window.display();
		}*/
	}

    void run()
    {
		// demo2();
		// demo1();
        demo0();
    }
}