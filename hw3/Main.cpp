//
// Created by moaad on 5/15/2021.
//

#include <iomanip>
#include "iostream"
#include "Vector2d.h"
#include "Simulator.h"

using namespace std;


int main() {

    string cmd;
    bool disc = false;
    cin >> cmd;
    AirHockeyTable hockeyTable;
    while (cmd != "simulate") {

        if (cmd == "disc") {
            disc = true;
            double x, y, vx, vy, r;
            cin >> x >> y >> vx >> vy >> r;
            if (cin.fail()) {
                cerr << "Error: illegal input." << endl;
                return -1;
            }
            Vector2d p(x, y);
            Vector2d v(vx, vy);
            Disc d(p, v, r);
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
            Wall w(p1, p2);
            if (!hockeyTable.AddWall(w))
                return -1;
        } else {
            cerr << "Error: illegal input." << endl;
            return -1;
        }
        cin >> cmd;
    }
    if (disc) {
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