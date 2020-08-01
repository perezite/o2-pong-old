#include "WindowDemo1.h"
#include "RendererDemo1.h"
#include "RendererDemo2.h"

#include <iostream>

using namespace std;

int main()
{
	// windowDemo1::run();
	//rendererDemo1::run();
	rendererDemo2::run();

	cout << "done..." << endl;
	cin.get();

	return 0;
}
