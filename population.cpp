#include "population.h"
#include "chromosome.h"

const int POP_SIZE = 100;
const int GEN_SIZE = 100;

Population::Population(const int initial_state[ROW][COL])
{
    cout << "population constructor" << endl;
	for(int i=0;i<POP_SIZE;++i)
	{
		Chromosome* temp = new Chromosome(initial_state, true);
		population.push_back(temp);
	}
	generations = 0;
}

Population::~Population()
{
	population.clear();
	generations = 0;
}

//  Newly generated children have a probability of their genes being mutated
void Population::mutatePct(int child_state[ROW][COL])
{
    cout << "mutatPCT" << endl;
    int pct = rand() % 100;
    if(pct < 30)
    {
        int cell_mutate = rand() % 4;
        for(int i = 0; i < ROW; ++i)
        {
            for(int j = cell_mutate; j < COL; j+=2)
            {
                child_state[i][j] = rand() % 9 + 1;
            }
        }
    }
}

//  Breeds two new children from the chosen parents, and adding them into the new population.
int Population::breed(const int parent1, const int parent2)
{
    cout << "parent1: " << parent1 << endl;
    cout << "parent2: " << parent2 << endl;

    cout << "breed" << endl;
    int child1[ROW][COL];
    int child2[ROW][COL];

    //  Random cross section index [1-7]
    int cross = rand() % 7 + 1;
    //  Determines which rows will be undergo crossover  
    for(int i = 0; i < ROW; ++i)
    {
        //  Selected rows from both parents will be crossed over 
        if(i < cross)
        {
            for(int j = 0; j < COL; ++j)
            {
                child1[i][j] = population[parent1]->board[i][j];
                child2[i][j] = population[parent2]->board[i][j];
            }
        }
        else
        {
            for(int j = 0; j < COL; ++j)
            {
                child1[i][j] = population[parent2]->board[i][j];
                child2[i][j] = population[parent1]->board[i][j];
            }
        }
    }

    //  There a probability that the childrens gene will mutate randomly
    //mutatePct(child1);
    //mutatePct(child2);

	Chromosome* temp1 = new Chromosome(child1, false);
	population.push_back(temp1);

	Chromosome* temp2 = new Chromosome(child2, false);
	population.push_back(temp2);

    return 0;
}

bool compare(const Chromosome* arg1, const Chromosome* arg2)
{
    return arg1->fitness_score > arg2->fitness_score;
}

int Population::solve(const int initial[ROW][COL])
{
    cout << "solve" << endl;
    int parent1, parent2;
    int pop_size;
    //bool flag;

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
            int total = totalFit();
            cout << "totalfitness: " << total << endl;
            parent1 = chooseParent(total);
            parent2 = chooseParent(total);
            breed(parent1, parent2);
            pop_size = population.size();
            
        }while(pop_size < POP_SIZE);

        ++gen_count;

        /*
        for(int j = 0; j < 9; ++j)
        {
            for(int k = 0; k < 9; ++k)
            {
                cout << population[0]->board[j][k];
            }
            cout << endl;
        }
        */

    //}while(gen_count < GEN_SIZE && flag == false);
    }while(gen_count < GEN_SIZE);
   
    generations = gen_count;

    return 0;
  
}

int Population::totalFit()
{
    int total = 0;
    for(int i = 0; i < POP_SIZE; ++i)
    {
        total += population[i]->fitness_score;
    }
    return total;
}

int Population::chooseParent(int total)
{
    int random = rand() % total;
    int i = 0;
    while(random > 0){
        random -= population[i]->fitness_score;
        if(random <= 0)
        {
            return i;
        }
        else
        {
           ++i;  
        }
    }

    return -1;
}
