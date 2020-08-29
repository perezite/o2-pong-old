#include "CameraDemo1.h"
#include "WindowV3.h"
#include "RectangleShapeV2.h"
#include "CircleShapeV2.h"
#include "EventsV3.h"
#include "CameraV1.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace o2;

namespace cameraDemo1
{  
    void demo0()
    {
        v3::Window window(v1::Vector2i(400, 400), "Pong");
        v2::RectangleShape rectangle(1);
        v1::Camera camera;
        v2::Renderer renderer;

        camera.setSize(4, 2);

        while (window.isOpen())
        {
            v3::Events::update();
            if (v3::Events::hasCloseRequest(window))
                window.close();

            window.clear();  
            renderer.draw(rectangle.getVertexArray().getVertices(), rectangle.getVertexArray().getPrimitiveType(), camera);
            window.display();
        }
    }

    void run()
    {
        demo0();
    }
}