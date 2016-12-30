//
// Created by Tucker Strausbaugh on 11/25/16.
//

#include <unistd.h>
#include <cmath>
#include <iostream>
#include <vector>

#include "Vehicle.h"

using namespace std;

int main()
{
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Vehicle(60.0, 0.0));
    vehicles.push_back(new Vehicle(55.0, 0.05));
    vehicles.push_back(new Vehicle(50.0, 0.10));

    for (auto& vehicle : vehicles)
        vehicle->drive();

    bool collision = false;
    while (!collision)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        for (auto& vehicle: vehicles)
        {
            cout << "location: " << vehicle->location.distance << "mi\n";

            for (auto& i: vehicles)
            {
                if (vehicle != i && abs(vehicle->location.distance - i->location.distance) < 0.01)
                    collision = true;
            }
        }

        cout << endl;

        this_thread::sleep_until(start + chrono::milliseconds(50));
    }

    cout << "Stopping Threads" << endl;
    for (auto& vehicle: vehicles)
        vehicle->stopThread();

    for (auto& vehicle: vehicles)
        cout << "location: " << vehicle->location.distance << "mi" << endl;

    return 0;
}