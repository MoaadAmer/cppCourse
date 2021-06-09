//
// Created by moaad on 5/15/2021.
//

#include <iomanip>
#include "iostream"
#include "Vector2d.h"
#include "Simulator.h"
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"

using namespace std;


int main() {

    string cmd;
    bool discInput = false;
    cin >> cmd;
    AirHockeyTable hockeyTable;
    while (cmd != "simulate") {

        if (cmd == "disc" || cmd == "exploding_disc" || cmd == "shrinking_disc") {
            discInput = true;
            double x, y, vx, vy, r;
            cin >> x >> y >> vx >> vy >> r;
            if (cin.fail()) {
                cerr << "Error: illegal input." << endl;
                return -1;
            }
            Vector2d p(x, y);
            Vector2d v(vx, vy);
            Disc *d = NULL;
            if (cmd == "disc") {
                d = new Disc(p, v, r);
            } else if (cmd == "exploding_disc") {
                d = new ExplodingDisc(p, v, r);

            } else if (cmd == "shrinking_disc") {
                d = new ShrinkingDisc(p, v, r);
            }
            if (!hockeyTable.addDisc(d))
                return -1;
        } else if (cmd == "wall") {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (cin.fail()) {
                cerr << "Error: illegal input." << endl;
                return -1;
            }

            Vector2d p1(x1, y1);
            Vector2d p2(x2, y2);
            Wall *w = new Wall(p1, p2);
            if (!hockeyTable.AddWall(w))
                return -1;
        } else {
            cerr << "Error: illegal input." << endl;
            return -1;
        }
        cin >> cmd;
    }
    if (discInput) {
        double time, dt;
        cin >> time >> dt;
        if (!cin.fail()) {
            Simulator s(time, dt, hockeyTable);
            s.simulate();
            return 1;
        }
    }
    cerr << "Error: illegal input." << endl;
    return -1;
}