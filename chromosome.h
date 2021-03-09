#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Chromosome
{
    public:
        Chromosome();
        Chromosome(string newState);
        string makeState();
        int fitnessEval();
        void printState();

    private:
        string state;
        int fitness_score;
};

#endif
