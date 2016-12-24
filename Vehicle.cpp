//
// Created by Tucker Strausbaugh on 11/25/16.
//

#include <iostream>
#include <random>
#include <thread>

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(double avgSpeed)
{
    //cout << "Vehicle()" << endl;

    this->avgSpeed = avgSpeed;
}

Vehicle::~Vehicle()
{
    //cout << "~Vehicle()" << endl;
}

void Vehicle::drive()
{
    //cout << "drive()" << endl;

    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine((unsigned int)seed);
    normal_distribution<double> speed(avgSpeed, 1);

    while (true)
    {
        cout << speed(engine) << endl;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}