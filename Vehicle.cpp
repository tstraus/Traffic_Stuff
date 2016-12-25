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
    mux.lock();
    threadShouldBeRunning = true;
    mux.unlock();

    driveThread = new thread(&Vehicle::driveLoop, this, true);
}

void Vehicle::stopThread()
{
    mux.lock();
    threadShouldBeRunning = false;
    mux.unlock();

    driveThread->join();
}

void Vehicle::driveLoop(bool asdf)
{
    cout << "driveLoop()" << endl;

    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine((unsigned int)seed);
    normal_distribution<double> nextVelocity(avgVelocity, 1);

    while (threadShouldBeRunning)
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();

        mux.lock();
        location.distance += velocity * (updateRate / 1000.0 / 60.0 / 60.0);
        velocity = nextVelocity(engine);
        mux.unlock();

        //cout << "distance: " << location.distance << "mi\n";
        //cout << "velocity: " << velocity << "mph\n";

        this_thread::sleep_until(start + chrono::milliseconds(updateRate));
    }
}