#include "Copyable.h"
#include "NonVirtualEcs.h"

#include <iostream>

using namespace std;

int main()
{
    // copyable::run();
    nonVirtualEcs::run();

    cout << "done ..." << endl;
    cin.get();

    return 0;
}