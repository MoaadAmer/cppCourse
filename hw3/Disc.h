//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_DISC_H
#define CPPCOURSE_DISC_H

#include "Vector2d.h"
#include "Wall.h"
#include "iostream"

using namespace std;

class Disc {


private:
    Vector2d location;
    Vector2d velocity;

    double r;
    double m;


public:

    Disc(const Vector2d &p, const Vector2d &v, double r) : location(p), velocity(v), r(r), m(r * r) {  }

    Vector2d getLocation() const { return location; }

    void setLocation(const Vector2d &point) { location = point; }

    Vector2d getVelocity() const { return velocity ;}

    void setVelocity(const Vector2d &v) { velocity = v; }

    friend ostream &operator<<(ostream &out, const Disc &disc);

    bool operator==(const Disc &disc) const;

    bool operator!=(const Disc &disc) const;

    bool doesCollide(const Disc &disc) const;

    double getMass() const { return m; }

    double getRadius() const { return r; }

};


ostream &operator<<(ostream &out, const Disc &disc);

#endif //CPPCOURSE_DISC_H
