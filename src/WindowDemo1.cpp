#include "WindowDemo1.h"
#include "WindowV1.h"

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
    
    void run()
    {
        demo0();
    }
}