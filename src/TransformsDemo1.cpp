#include "TransformsDemo1.h"
#include "WindowV1.h"
#include "WindowV2.h"
#include "WindowV3.h"
#include "RectangleShapeV1.h"
#include "RectangleShapeV2.h"
#include "VertexArrayV1.h"
#include "RendererV2.h"
#include "EventsV2.h"
#include "EventsV3.h"
#include "TransformV1.h"
#include "ClockV1.h"
#include "MathV1.h"

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
        v1::RectangleShape rectangle(.3f);
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

    void demo3()
    {
        v3::Window window(v1::Vector2i(400, 400), "Pong");
        v1::RectangleShape rectangle(.3f);

        rectangle.setPosition(.5f, 0);
        rectangle.setRotation(45);
        rectangle.setScale(1, .5f);

        while (window.isOpen())
        {
            v3::Events::update();
            if (v3::Events::hasCloseRequest(window))
                window.close();

            window.clear();
            v1::VertexArray& vertexArray = rectangle.getVertexArray();
            window.draw(vertexArray.getVertices(), vertexArray.getPrimitiveType(), rectangle.getTransform());
            window.display();
        }
    }

    void demo4()
    {
        v3::Window window(v1::Vector2i(400, 400), "Pong");
        v2::RectangleShape rectangle(.3f);
        v2::Renderer renderer;

        rectangle.setPosition(.5f, 0);
        rectangle.setRotation(45);
        rectangle.setScale(1, .5f);

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
    
    void demo5()
    {
        v3::Window window(v1::Vector2i(400, 400), "Pong");
        v2::RectangleShape rectangle(.3f);
        v1::Transform transform;

        rectangle.setPosition(0, .5f);
        transform.translate(.5f, 0);

        while (window.isOpen())
        {
            v3::Events::update();
            if (v3::Events::hasCloseRequest(window))
                window.close();

            window.clear();
            rectangle.draw(window, transform);
            window.display();
        }
    }

    void demo6()
    {
        v3::Window window(v1::Vector2i(400, 400), "Pong");
        v2::RectangleShape rectangle(.3f);
        v1::Clock clock;

        while (window.isOpen())
        {
            v3::Events::update();
            if (v3::Events::hasCloseRequest(window))
                window.close();

            auto test = clock.getElapsedTime();
            auto test2 = test.asSeconds();
            rectangle.setRotation(clock.getElapsedTime().asSeconds() * v1::math::ToDegrees * 3);

            window.clear();
            rectangle.draw(window);
            window.display();
        }
    }

    void run()
    {
        demo6();
        //demo5();
        //demo4();
        //demo3();
        // demo2();
        //demo1();
        //demo0();
    }
}