//
// Created by Tucker Strausbaugh on 11/25/16.
//

#include <iostream>
#include <random>

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(double avgVelocity, double startingDistance, unsigned char startingLane, unsigned int updateRate)
{
    //cout << "Vehicle()" << endl;

    threadShouldBeRunning = false;

    velocity = avgVelocity;
    this->avgVelocity = avgVelocity;
    location.distance = startingDistance;
    location.lane = startingLane;
    this->updateRate = updateRate;
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
    threadShouldBeRunning = false;

    driveThread->join();
}

void Vehicle::driveLoop(bool asdf)
{
    //cout << "driveLoop()" << endl;

    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine((unsigned int)seed);
    normal_distribution<double> nextVelocity(avgVelocity, 1);

    while (threadShouldBeRunning)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        location.distance = location.distance + velocity * (updateRate / 3600000.0);
        velocity = nextVelocity(engine);

        this_thread::sleep_until(start + chrono::milliseconds(updateRate));
    }
}