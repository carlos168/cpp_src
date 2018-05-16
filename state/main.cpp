#include <iostream>
//#include "tank.h"
#include "building.h"

using namespace std;
class SiegeTank;

int main()
{
    concreteBuilding cb("兵营");
    cb.production();
    cb.injured();
    cb.repair();
    cb.show();
    return 0;
}

