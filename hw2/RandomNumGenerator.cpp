//
// Created by moaad on 4/18/2021.
//

#include "RandomNumGenerator.h"

int RandomNumGenerator::generateRandomNum() {

    const unsigned int a = 22695477;
    const unsigned int c = 1;
    x = a*x + c;
    return (x & 0x7fffffff) >> 16;


}



