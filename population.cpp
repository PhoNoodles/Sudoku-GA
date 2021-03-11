#include "population.h"
#include "chromosome.h"

const int POP_SIZE = 500;
const int GEN_SIZE = 1000;

Population::Population(const int initial_state[ROW][COL])
{
	for(int i=0;i<POP_SIZE;++i)
	{
		//Chromosome * temp = new Chromosome();
		population.clear();
	}
	generations=0;
}

Population::~Population()
{
	population.clear();
	generations=0;

}

bool compare(const Chromosome* arg1, const Chromosome* arg2)
{
    //  Need function that gets fitness score
    //return arg1->fitness_score > arg2->fitness_score;
}

int Population::solve(vector<vector<int>> initial)
{
    int parent1, parent2;
    int pop_size;
    bool flag;

    int gen_count = 1;
    do{

        //  Sorting population from highest to lowest fitness score
        sort(population.begin(), population.end(), compare);

        //  Checks if the population is in a solved state (TBD)
        //flag = checkSolved();
        
        //  Removes the least fittest 50% from the popultion
        for(int i = 0; i < POP_SIZE/2; ++i)
        {
            population.pop_back();
        }

        //  Choose parents and breeds, repopulating the population until the
        //  population is back to its original size
        do{
            //parent1 = chooseParent();
            //parent2 = chooseParent();
            //breed(parent1, parent2);
            //pop_size = population.size();
            
        }while(pop_size < POP_SIZE);

        ++gen_count;

    }while(gen_count < GEN_SIZE && flag == false);

    generations = gen_count;

    return flag;

}
