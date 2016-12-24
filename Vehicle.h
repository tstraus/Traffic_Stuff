//
// Created by Tucker Strausbaugh on 11/25/16.
//

#ifndef __TRAFFIC_STUFF_VEHICLE_H__
#define __TRAFFIC_STUFF_VEHICLE_H__

class Vehicle
{
public:
    Vehicle(double avgSpeed, double startingDistance = 0.0, unsigned char startingLane = 0);

    ~Vehicle();

    void drive();

private:
    double avgSpeed;

    struct {
        double distance;

        unsigned char lane;
    } location;
};

#endif //__TRAFFIC_STUFF_VEHICLE_H__
