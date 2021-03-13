#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ROW = 9;
const int COL = 9;

class Chromosome
{
    public:
        Chromosome(const int initial_state[ROW][COL]);
        void fillBoard();
        int fitnessEval();
        void printState();
	int checkedAlready(int array [],int num);
        void copyBoard(const int initial_state[COL][ROW]);

        int board[ROW][COL];
        int fitness_score;
};

#endif
