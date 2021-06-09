//
// Created by moaad on 6/5/2021.
//

#include "ShrinkingDisc.h"


void ShrinkingDisc::specialAction(DiscsList &list) {
    setDidCollide(false);
    setRadius(getRadius() * 0.9);
    setGeneration(getGeneration() + 1);
    if (getGeneration() < 3)
        list.insert(createCopy());
}

Disc *ShrinkingDisc::createCopy() {
    return new ShrinkingDisc(getLocation(), getVelocity(), getRadius(),
                             getMass(), getGeneration());
}



