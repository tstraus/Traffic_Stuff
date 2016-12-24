#include <unistd.h>
#include <iostream>

#include "Vehicle.h"

using namespace std;

int main()
{
    Vehicle vehicle(60.0);
    vehicle.drive();

    //cin.get();
    sleep(60);

    cout << "Stopping Threads" << endl;
    vehicle.stopThread();

    return 0;
}