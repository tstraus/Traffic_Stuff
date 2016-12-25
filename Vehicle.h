//
// Created by Tucker Strausbaugh on 11/25/16.
//

#ifndef __TRAFFIC_STUFF_VEHICLE_H__
#define __TRAFFIC_STUFF_VEHICLE_H__

#include <thread>
#include <mutex>

using namespace std;

class Vehicle
{
public:
    Vehicle(double avgVelocity, double startingDistance = 0.0, unsigned char startingLane = 0, unsigned int updateRate = 50);

    ~Vehicle();

    void drive();

    void stopThread();

    double velocity;

    struct {
        double distance;

        unsigned char lane;
    } location;

private:
    void driveLoop(bool asdf);

    double avgVelocity;

    unsigned int updateRate;

    thread* driveThread;

    bool threadShouldBeRunning;

    mutex mux;
};

#endif //__TRAFFIC_STUFF_VEHICLE_H__
