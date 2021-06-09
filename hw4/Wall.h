//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_WALL_H
#define CPPCOURSE_WALL_H

#include "iostream"
#include "Vector2d.h"
#include "Disc.h"

class Disc;

using namespace std;

class Wall {


private:
    Vector2d p1, p2;


public:

    Wall(const Vector2d &p1, const Vector2d &p2) : p1(p1), p2(p2) {}

//    friend ostream &operator<<(ostream &out, const Wall &wall);

    Vector2d getP1() const { return p1; }

    Vector2d getP2() const { return p2; }

    bool operator==(const Wall &wall) const;

    bool operator!=(const Wall &wall) const;

    bool doesCollide(const Disc &disc) const;

    Vector2d closestPoint(const Vector2d &point) const;
};


//ostream &operator<<(ostream &out, const Wall &wall);

#endif //CPPCOURSE_WALL_H
