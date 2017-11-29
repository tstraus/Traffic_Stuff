//
// Created by Tucker Strausbaugh on 11/25/16.
//

#ifndef __TRAFFIC_STUFF_VEHICLE_H__
#define __TRAFFIC_STUFF_VEHICLE_H__

#include <thread>
#include <atomic>

using namespace std;

class Vehicle
{
public:
    Vehicle(double avgVelocity, double startingDistance = 0.0, unsigned char startingLane = 0, unsigned int updateRate = 50);

    ~Vehicle();

    void drive();

    void stopThread();

    atomic<double> velocity;

    struct Location {
        atomic<double> distance;

        atomic<unsigned char> lane;
    } location;

private:
    void driveLoop(bool asdf);

    double avgVelocity;

    unsigned int updateRate;

    thread* driveThread;

    atomic<bool> threadShouldBeRunning;
};

#endif //__TRAFFIC_STUFF_VEHICLE_H__
