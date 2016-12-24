//#include <unistd.h>
#include <iostream>

#include "Vehicle.h"

using namespace std;

int main()
{
    Vehicle vehicle(55.0);
    vehicle.drive();

    cin.get();

    return 0;
}