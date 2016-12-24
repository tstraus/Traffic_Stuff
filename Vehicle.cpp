//
// Created by Tucker Strausbaugh on 11/25/16.
//

#include <iostream>
#include <random>

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(double avgSpeed, double startingDistance, unsigned char startingLane)
{
    //cout << "Vehicle()" << endl;

    threadShouldBeRunning = false;

    this->avgSpeed = avgSpeed;
    location.distance = startingDistance;
    location.lane = startingLane;
}

Vehicle::~Vehicle()
{
    //cout << "~Vehicle()" << endl;
}

void Vehicle::drive()
{
    threadShouldBeRunning = true;

    driveThread = new thread(&Vehicle::driveLoop, this, true);
}

void Vehicle::stopThread()
{

}

void Vehicle::driveLoop(bool asdf)
{
    cout << "driveLoop()" << endl;

    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine((unsigned int)seed);
    normal_distribution<double> speed(avgSpeed, 1);

    while (threadShouldBeRunning)
    {
        cout << speed(engine) << endl;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}