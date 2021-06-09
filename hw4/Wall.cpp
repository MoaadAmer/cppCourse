//
// Created by moaad on 5/15/2021.
//

#include "Wall.h"
#include <cmath>


bool Wall::operator==(const Wall &wall) const {
    return this->p1.getX() == wall.getP1().getX() && this->p1.getY() == wall.getP1().getY() &&
           this->p2.getX() == wall.getP2().getX() && this->p2.getY() == wall.getP2().getY();
}

bool Wall::operator!=(const Wall &wall) const {
    return *this == wall;
}


Vector2d Wall::closestPoint(const Vector2d &point) const {
    if (p1 == p2)
        return p1;
    double alpha = ((point - p1) * (p2 - p1)) / pow(normalizeVec(p1 - p2), 2);
    if (alpha < 0)
        return p1;
    else if (alpha > 1)
        return p2;
    Vector2d res = p1 + (alpha * (p2 - p1));
    return res;
}

bool Wall::doesCollide(const Disc &disc) const {
    double d = normalizeVec(disc.getLocation() - closestPoint(disc.getLocation()));
    return d <= disc.getRadius();
}








