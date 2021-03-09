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
        Chromosome(vector<vector<int>> newState);
        vector<vector<int>> makeState();
        int fitnessEval();
        void printState();

    private:
        vector<vector<int>> state;
        int fitness_score;
};

#endif
