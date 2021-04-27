//
// Created by moaad on 4/18/2021.
//

#include <iostream>
#include "Backgammon.h"

using namespace std;


int main() {

    int seed;
    cout << "Enter seed" << endl;
    if (!(cin >> seed)) {
        cout << "Missing user input - quiting game." << endl;
        return -1;
    }

    Backgammon backgammon(seed);
    backgammon.start();


}



