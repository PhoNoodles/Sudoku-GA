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
        void fillBoard();
        void readIn();
        int fitnessEval();
        void printState();

    private:
        int board[9][9];
        int fitness_score;
};

#endif
