//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_DISC_H
#define CPPCOURSE_DISC_H

#include "Vector2d.h"
#include "Wall.h"
#include "iostream"
#include "DiscsList.h"

using namespace std;

class Disc {

protected:
    Vector2d location;
    Vector2d velocity;

    double r;
    double m;
    char gen;
    bool didCollide;

public:

    Disc(const Vector2d &p, const Vector2d &v, double r) : location(p), velocity(v), r(r), m(r * r), gen(0),
                                                           didCollide(false) {}

    Disc(const Vector2d &p, const Vector2d &v, double r, double mass, char gen) : location(p), velocity(v), r(r),
                                                                                  m(mass), gen(gen),
                                                                                  didCollide(false) {}

    virtual ~Disc() {}

    Vector2d getLocation() const { return location; }

    void setLocation(const Vector2d &point) { location = point; }

    Vector2d getVelocity() const { return velocity; }

    void setVelocity(const Vector2d &v) { velocity = v; }

    friend ostream &operator<<(ostream &out, const Disc &disc);

    bool operator==(const Disc &disc) const;

    bool operator!=(const Disc &disc) const;

    bool doesCollide(const Disc &disc) const;

    double getMass() const { return m; }

    double getRadius() const { return r; }

    void setRadius(double r) { this->r = r; }

    char getGeneration() const { return gen; }

    void setGeneration(char value) { gen = value; }

    bool getDidCollide() const { return didCollide; }

    void setDidCollide(bool collide) { didCollide = collide; }

    virtual void specialAction(DiscsList &list);

    virtual Disc *createCopy();


};


ostream &operator<<(ostream &out, const Disc &disc);

#endif //CPPCOURSE_DISC_H
