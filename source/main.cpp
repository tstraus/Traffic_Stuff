//
// Created by Tucker Strausbaugh on 11/25/16.
//

#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

#include "Vehicle.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
    vector<shared_ptr<Vehicle>> vehicles;

    ifstream file("Vehicles.json");
    json config;
    file >> config;

    for (auto& vehicle: config["vehicles"])
        vehicles.push_back(make_shared<Vehicle>(vehicle["avgVelocity"], vehicle["startingDistance"], vehicle["startingLane"], vehicle["updateRate"]));

   for (auto& vehicle : vehicles)
        vehicle->drive();

    unsigned int first, second;
    bool collision = false;
    pair<unsigned int, unsigned int> collidedVehicles;

    while (!collision)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        first = 1;
        for (auto& vehicle: vehicles)
        {
            cout << "location: " << vehicle->location.distance << "mi\n";

            second = 1;
            for (auto& i: vehicles)
            {
                if (vehicle != i && vehicle->location.lane == i->location.lane && abs(vehicle->location.distance - i->location.distance) < 0.00287247) // length of a mid-size sedan in miles
                {
                    collidedVehicles.first = first;
                    collidedVehicles.second = second;
                    collision = true;
                }

                second++;
            }

            first++;
        }

        cout << endl;

        this_thread::sleep_until(start + chrono::milliseconds(50));
    }

    for (auto& vehicle: vehicles)
        vehicle->stopThread();

    cout << "Collision between vehicle " << collidedVehicles.second << " and vehicle " << collidedVehicles.first << endl;

    for (auto& vehicle: vehicles)
        cout << "location: " << vehicle->location.distance << "mi" << endl;

    return 0;
}