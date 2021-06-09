//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_AIRHOCKEYTABLE_H
#define CPPCOURSE_AIRHOCKEYTABLE_H

#include "DiscsList.h"
#include "WallsList.h"

class AirHockeyTable {

private:

    DiscsList dList;
    WallsList wList;


public:


    bool addDisc(const Disc &disc);

    bool AddWall(const Wall &wall);

    const DiscsList &getDiscs() const { return dList; }

    DiscsList &getMutableDiscs() { return dList; }

    const WallsList &getWalls() const { return wList; };

    WallsList &getMutableWalls() { return wList; }

    bool doesCollideWithDisc(const Disc &disc) const;

    bool doesCollideWithWall(const Disc &disc) const;

    bool doesCollideWithDisc(const Wall &wall) const;

};

#endif //CPPCOURSE_AIRHOCKEYTABLE_H
