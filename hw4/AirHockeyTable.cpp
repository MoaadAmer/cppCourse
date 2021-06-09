//
// Created by moaad on 5/15/2021.
//

#include "AirHockeyTable.h"


bool AirHockeyTable::addDisc(Disc *disc) {
    if (!doesCollideWithDisc(*disc)) {
        if (!doesCollideWithWall(*disc)) {
            (*dList).insert(disc);
            return true;
        }
        cerr << "Error: disc to wall collision detected in initial configuration" << endl;
    }
    cerr << "Error: disc to disc collision detected in initial configuration" << endl;
    return false;

}

bool AirHockeyTable::AddWall(Wall *wall) {
    if (!doesCollideWithDisc(*wall)) {
        (*wList).insert(wall);
        return true;
    }
    cerr << "Error: disc to wall collision detected in initial configuration" << endl;
    return false;
}

bool AirHockeyTable::doesCollideWithDisc(const Disc &disc) const {
    const DiscsList &discs = getDiscs();
    for (int i = 0; i < discs.size(); ++i) {
        if (disc.doesCollide(discs[i]))
            return true;
    }
    return false;
}

bool AirHockeyTable::doesCollideWithWall(const Disc &disc) const {
    const WallsList &walls = getWalls();
    for (int i = 0; i < walls.size(); ++i) {
        if (walls[i].doesCollide(disc))
            return true;
    }
    return false;
}

bool AirHockeyTable::doesCollideWithDisc(const Wall &wall) const {
    const DiscsList &discs = getDiscs();
    for (int i = 0; i < discs.size(); ++i) {
        if (wall.doesCollide(discs[i]))
            return true;
    }
    return false;
}

void AirHockeyTable::clear() {
    dList->clear();
    delete dList;
    wList->clear();
    delete wList;
}


