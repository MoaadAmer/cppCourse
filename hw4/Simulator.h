//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_SIMULATOR_H
#define CPPCOURSE_SIMULATOR_H

#include "AirHockeyTable.h"

class Simulator {

private:
    double time;
    double deltaT;
    AirHockeyTable &hockeyTable;

public:
    void simulate();

    void print(double time);

    void updateDiscLocation(int discNum);

    bool handleCollisionBetweenDiscs(int disNum);

    void updateVelocity(Disc &disc1, Disc &disc2);

    bool handleCollisionBetweenWallsAndDiscs(int disNum);

    void updateVelocity(Disc &disc, Vector2d closestPoint);

    Simulator(double time, double dt, AirHockeyTable &table) : time(time), deltaT(dt), hockeyTable(table) {}
};


#endif //CPPCOURSE_SIMULATOR_H
