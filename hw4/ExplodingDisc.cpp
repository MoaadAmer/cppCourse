//
// Created by moaad on 6/5/2021.
//

#include "ExplodingDisc.h"
#include <cmath>


void ExplodingDisc::specialAction(DiscsList &list) {

    setDidCollide(false);
    setGeneration(getGeneration() + 1);
    if (getGeneration() < 3) {
        double c = 0.99;
        double rTag = (2 * sqrt(3) - 3) * c * getRadius();
        double a = (4 - 2 * sqrt(3)) * getRadius();

        Vector2d pZero = getLocation() + Vector2d(0, a);
        Vector2d vZero = getVelocity() + Vector2d(0, 1);
        double mass = getMass() / 3;
        ExplodingDisc *exp = new ExplodingDisc(pZero, vZero, rTag, mass, getGeneration());
        list.insert(exp);

        Vector2d pOne = getLocation() + Vector2d(getRadius() - a, -a / 2);
        Vector2d vOne = getVelocity() + Vector2d(sqrt(3) / 2, -0.5);
        exp = new ExplodingDisc(pOne, vOne, rTag, mass, getGeneration());
        list.insert(exp);

        Vector2d pTwo = getLocation() + Vector2d(-(getRadius() - a), -a / 2);
        Vector2d vTwo = getVelocity() + Vector2d(-sqrt(3) / 2, -0.5);
        exp = new ExplodingDisc(pTwo, vTwo, rTag, mass, getGeneration());
        list.insert(exp);

    }
}

Disc *ExplodingDisc::createCopy() {
    return new ExplodingDisc(getLocation(), getVelocity(), getRadius(),
                             getMass(), getGeneration());
}
