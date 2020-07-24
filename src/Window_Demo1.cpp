#include "WindowV1.h"
#include <iostream>
#include "Window_Demo1.h"

using namespace std;
using namespace o2;

namespace windowDemo1
{
    void demo0()
    {
        v1::Window window(v1::Vector2i(400, 200), "Pong");

        while (window.isOpen())
        {
            window.update();
        }
    }

    void run()
    {
        demo0();
    }
}