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
    
    void run()
    {
        demo0();
    }
}