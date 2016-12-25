#include <unistd.h>
#include <cmath>
#include <iostream>

#include "Vehicle.h"

using namespace std;

int main()
{
    Vehicle vehicle1(60.0, 0.0);
    Vehicle vehicle2(55.0, 0.05);

    vehicle1.drive();
    vehicle2.drive();

    for (int i = 0; i < 1200; i++)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        double diff = abs(vehicle1.location.distance - vehicle2.location.distance);

        cout << "diff: " << diff << endl;

        if (diff < 0.01)
            break;

        this_thread::sleep_until(start + chrono::milliseconds(50));
    }

    //cin.get();
    //sleep(60);

    cout << "Stopping Threads" << endl;
    vehicle1.stopThread();
    vehicle2.stopThread();

    cout << "-----Vehicle 1-----" << endl;
    cout << "location: " << vehicle1.location.distance << "mi" << endl;
    cout << "-----Vehicle 2-----" << endl;
    cout << "location: " << vehicle2.location.distance << "mi" << endl;

    return 0;
}