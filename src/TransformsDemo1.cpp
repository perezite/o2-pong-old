#include "TransformsDemo1.h"
#include "WindowV1.h"
#include "WindowV2.h"
#include "RectangleShapeV1.h"
#include "VertexArrayV1.h"
#include "RendererV2.h"
#include "EventsV2.h"
#include "TransformV1.h"

using namespace std;
using namespace o2;

namespace transformsDemo1
{
	void demo0()
	{
		v2::Window window(v1::Vector2i(400, 400), "Pong");
		v1::RectangleShape rectangle(1);
		v2::Renderer renderer;
		v1::Transform transform;

		
		transform.rotate(30);
		transform.translate(.1f, .45f);

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();
			v1::VertexArray& vertexArray = rectangle.getVertexArray();
			renderer.draw(vertexArray.getVertices(), vertexArray.getPrimitiveType(), transform);
			window.display();
		}
	}

    void demo1()
    {
        v2::Window window(v1::Vector2i(400, 400), "Pong");
        v1::RectangleShape rectangle(.1f, .1f);
        v2::Renderer renderer;
        v1::Transform transform;

        transform.rotate(45);
        transform.translate(.5f, 0);
        transform.scale(1, .5f);

        while (window.isOpen())
        {
            v2::Events::update();
            if (v2::Events::hasCloseRequest(window))
                window.close();

            window.clear();
            v1::VertexArray& vertexArray = rectangle.getVertexArray();
            renderer.draw(vertexArray.getVertices(), vertexArray.getPrimitiveType(), transform);
            window.display();
        }
    }

    void demo2()
    {
        v2::Window window(v1::Vector2i(400, 400), "Pong");
        v1::RectangleShape rectangle(.1f, .1f);
        v2::Renderer renderer;

        rectangle.setPosition(.5f, 0);
        rectangle.setRotation(45);
        rectangle.setScale(1, .5f);

        while (window.isOpen())
        {
            v2::Events::update();
            if (v2::Events::hasCloseRequest(window))
                window.close();

            window.clear();
            v1::VertexArray& vertexArray = rectangle.getVertexArray();
            renderer.draw(vertexArray.getVertices(), vertexArray.getPrimitiveType(), rectangle.getTransform());
            window.display();
        }
    }
    
    void run()
    {
        demo2();
        //demo1();
        //demo0();
    }
}