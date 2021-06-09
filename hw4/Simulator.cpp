//
// Created by moaad on 5/15/2021.
//

#include <sys/unistd.h>
#include "Simulator.h"
#include "iostream"
#include <iomanip>
#include "cmath"
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"

using namespace std;

void Simulator::simulate() {

    for (double i = 0; i <= time; i += deltaT) {
        print(i);
        DiscsList &discs = hockeyTable.getMutableDiscs();
        for (int j = discs.size() - 1; j >= 0; j--) {
            Vector2d prevLocation = discs[j].getLocation();
            updateDiscLocation(j);
            if (handleCollisionBetweenDiscs(j) || handleCollisionBetweenWallsAndDiscs(j)) {
                discs[j].setLocation(prevLocation);
            }
        }
        DiscsList *newDiscs = new DiscsList();

        for (int j = discs.size() - 1; j >= 0; j--) {

            if (!discs[j].getDidCollide()) {
                (*newDiscs).insert(discs[j].createCopy());
            } else {
                discs[j].specialAction(*newDiscs);

            }
        }
        hockeyTable.setDiscsList(newDiscs);

    }

}


void Simulator::print(double time) {
    if (time == 0)
        cout << time << ": ";
    else
        cout << fixed << setprecision(4) << time << ": ";
    hockeyTable.getDiscs().printInReverseOrder();
    cout << endl;

}


bool Simulator::handleCollisionBetweenDiscs(int disNum) {
    DiscsList &discs = hockeyTable.getMutableDiscs();
    bool collision = false;
    for (int i = 0; i < discs.size(); ++i) {
        if (disNum != i)
            if (discs[disNum].doesCollide(discs[i])) {
                updateVelocity(discs[disNum], discs[i]);
                collision = true;
                discs[disNum].setDidCollide(true);
                discs[i].setDidCollide(true);

            }
    }
    return collision;
}

void Simulator::updateDiscLocation(int disNum) {

    DiscsList &discs = hockeyTable.getMutableDiscs();
    Vector2d p(discs[disNum].getLocation().getX() + (discs[disNum].getVelocity().getX() * deltaT),
               discs[disNum].getLocation().getY() + (discs[disNum].getVelocity().getY() * deltaT));
    discs[disNum].setLocation(p);

}


//𝑑= (𝑝−𝑝′)/‖𝑝−𝑝′‖  normalized direction of collision
// Δ =((𝑣−𝑣′)∙𝑑)* 𝑑
// 𝑣 𝑛𝑒𝑤=𝑣−2𝑚′/𝑚+𝑚′ *Δ
// 𝑣′𝑛𝑒𝑤=𝑣′+2𝑚/𝑚+𝑚′ *Δ

//in case two discs collide

void Simulator::updateVelocity(Disc &disc1, Disc &disc2) {
    Vector2d d = (disc1.getLocation() - disc2.getLocation()) / normalizeVec(disc1.getLocation() - disc2.getLocation());
    Vector2d delta = ((disc1.getVelocity() - disc2.getVelocity()) * d) * d;
    Vector2d newV1 = disc1.getVelocity() - ((2 * disc2.getMass() / (disc1.getMass() + disc2.getMass())) * delta);
    Vector2d newV2 = disc2.getVelocity() + ((2 * disc1.getMass() / (disc1.getMass() + disc2.getMass())) * delta);

    disc1.setVelocity(newV1);
    disc2.setVelocity(newV2);

}


bool Simulator::handleCollisionBetweenWallsAndDiscs(int disNum) {

    const WallsList &wallsList = hockeyTable.getWalls();
    DiscsList &discs = hockeyTable.getMutableDiscs();
    bool collision = false;
    for (int i = 0; i < wallsList.size(); ++i) {
        if (wallsList[i].doesCollide(discs[disNum])) {
            updateVelocity(discs[disNum], wallsList[i].closestPoint(discs[disNum].getLocation()));
            collision = true;
            discs[disNum].setDidCollide(true);
        }
    }
    return collision;
}

void Simulator::updateVelocity(Disc &disc, Vector2d closestPoint) {

    Vector2d d = (disc.getLocation() - closestPoint) / (normalizeVec(disc.getLocation() - closestPoint));
    disc.setVelocity(disc.getVelocity() - (2 * (disc.getVelocity() * d) * d));
}




