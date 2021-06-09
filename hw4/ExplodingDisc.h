//
// Created by moaad on 6/5/2021.
//

#ifndef CPPCOURSE_EXPLODINGDISC_H
#define CPPCOURSE_EXPLODINGDISC_H


#include "Disc.h"


class ExplodingDisc : public Disc {


public:
    ExplodingDisc(Vector2d point, Vector2d velocity, double r) : Disc(point, velocity, r) {

    }

    ExplodingDisc(Vector2d point, Vector2d velocity, double r, double mass, char gen) : Disc(point, velocity, r, mass,
                                                                                             gen) {

    }

    virtual void specialAction(DiscsList &list);
    virtual Disc *createCopy();

};


#endif //CPPCOURSE_EXPLODINGDISC_H
