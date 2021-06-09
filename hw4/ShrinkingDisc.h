//
// Created by moaad on 6/5/2021.
//

#ifndef CPPCOURSE_SHRINKINGDISC_H
#define CPPCOURSE_SHRINKINGDISC_H


#include "Disc.h"

class ShrinkingDisc : public Disc {

public:
    ShrinkingDisc(Vector2d point, Vector2d velocity, double r) : Disc(point, velocity, r) {

    }

    ShrinkingDisc(Vector2d point, Vector2d velocity, double r, double m, char g) : Disc(point, velocity, r, m, g) {

    }


    virtual void specialAction(DiscsList &list);

    virtual Disc *createCopy();

};


#endif //CPPCOURSE_SHRINKINGDISC_H
