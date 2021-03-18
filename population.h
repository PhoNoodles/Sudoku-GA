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
        void mutatePct(int child_state[ROW][COL]);
        bool randomDeath(const int parent1, const int parent2);
        void breed(const int parent1, const int parent2);
        int solve(const int initial[ROW][COL]);
        void printPopulation();
        int totalFit();
	    int averageFitness();
        void copy(const int state[ROW][COL]);

    private:
        vector<Chromosome*> population;
        int generations;
        int first[ROW][COL]; 
        
};

#endif
