//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_AIRHOCKEYTABLE_H
#define CPPCOURSE_AIRHOCKEYTABLE_H

#include "DiscsList.h"
#include "WallsList.h"

class AirHockeyTable {

private:

    DiscsList *dList;
    WallsList *wList;


public:

    AirHockeyTable() : dList(new DiscsList()), wList(new WallsList()) {}

    ~AirHockeyTable() { clear(); }

    bool addDisc(Disc *disc);

    bool AddWall(Wall *wall);

    const DiscsList &getDiscs() const { return *dList; }

    DiscsList &getMutableDiscs() { return *dList; }

    void setDiscsList(DiscsList *list) {
        (*dList).clear();
        delete dList;
        dList = list;
    }

    const WallsList &getWalls() const { return *wList; };

    WallsList &getMutableWalls() { return *wList; }

    bool doesCollideWithDisc(const Disc &disc) const;

    bool doesCollideWithWall(const Disc &disc) const;

    bool doesCollideWithDisc(const Wall &wall) const;

    void clear();
};

#endif //CPPCOURSE_AIRHOCKEYTABLE_H
