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
	void demo1()
	{
		/*
		v1::Window window(v1::Vector2i(600, 400), "Pong");
		v1::Shader shader;
		v1::Renderer renderer;
		v1::VertexArray quad(v1::TriangleFan, 4);
		quad[0].position = v1::Vector2f(-.5f, -5.f);
		quad[1].position = v1::Vector2f(-.5f, -5.f);
		quad[2].position = v1::Vector2f(-.5f, -5.f);
		quad[3].position = v1::Vector2f(-.5f, -5.f);

		shader.loadDefaultShader();

		while (window.isOpen())
		{
			window.update();

			drawQuad2(v1::Vector2f(-.9f,  .3f), v1::Vector2f(.05f, .4f), shader);
			drawQuad2(v1::Vector2f( .9f, -.4f), v1::Vector2f(.05f, .4f), shader);

			window.display();
		}
		*/
	}

	void demo0()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		
		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			//drawQuad2(v1::Vector2f(-.9f, .3f), v1::Vector2f(.05f, .4f), shader);
			//drawQuad2(v1::Vector2f(.9f, -.4f), v1::Vector2f(.05f, .4f), shader);

			window.display();
		}
	}

    void run()
    {
        demo0();
    }
}