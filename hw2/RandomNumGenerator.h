//
// Created by moaad on 4/18/2021.
//

#ifndef CPPCOURSE_RANDOMNUMGENERATOR_H
#define CPPCOURSE_RANDOMNUMGENERATOR_H

class RandomNumGenerator {

public:
    explicit RandomNumGenerator(int seed) : x(seed) {}

    RandomNumGenerator();

    int generateRandomNum();

private:
    int x;

};

#endif //CPPCOURSE_RANDOMNUMGENERATOR_H
