#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "chromosome.h"

using namespace std;

class Population
{
    public:
        Population(const int initial_state[ROW][COL]);
        ~Population();

        bool checkSolved();
        int chooseParent(int total);
        int breed(const int parent1, const int parent2);
        int solve(vector<vector<int>> initial);
        void printPopulation();
        int totalFit();

    private:
        vector<Chromosome*> population;
        int generations;
        
};

#endif
