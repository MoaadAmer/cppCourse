//
// Created by moaad on 5/15/2021.
//

#include <iomanip>
#include "Disc.h"


bool Disc::operator==(const Disc &disc) const {
    return this->location.getX() == disc.getLocation().getX() && this->location.getY() == disc.getLocation().getY() &&
           this->velocity.getX() == disc.velocity.getX() && this->velocity.getX() == disc.velocity.getY() &&
           this->r == disc.r;
}

bool Disc::operator!=(const Disc &disc) const {
    return *this == disc;
}


ostream &operator<<(ostream &out, const Disc &disc) {
    out << fixed << "(" << setprecision(4) << disc.getLocation().getX() << ","
        << disc.getLocation().getY() << ")" << "/" << disc.getRadius();
    return out;
}


//    ‖𝑝−𝑝′‖≤𝑟+𝑟′

bool Disc::doesCollide(const Disc &disc) const {
    return normalizeVec(this->location - disc.location) <= this->r + disc.r;
}


void Disc::specialAction(DiscsList &list) {
    setDidCollide(false);
    list.insert(createCopy());

}

Disc *Disc::createCopy() {

    return new Disc(getLocation(), getVelocity(), getRadius(),
                    getMass(), getGeneration());
}
