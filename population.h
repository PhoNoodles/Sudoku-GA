#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <string>
#include <iostream>
#include "chromosome.h"

using namespace std;

class Population
{
    public:
        Population();
        ~Population();

        bool checkSolved();
        int chooseParent();
        int breed(const int parent1, const int parent2);
        int solve(vector<vector<int>> initial);
        void printPopulation();

    private:
        vector<Chromosome*> population;
        int generations;
        
};

#endif