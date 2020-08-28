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

        camera.setSize(100, 100);
        // window.setCamera(camera);

        auto test = v1::Transform();

        while (window.isOpen())
        {
            v3::Events::update();
            if (v3::Events::hasCloseRequest(window))
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