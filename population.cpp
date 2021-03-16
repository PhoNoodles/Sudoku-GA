#include "population.h"
#include "chromosome.h"

const int POP_SIZE = 1000;
const int GEN_SIZE = 100;

Population::Population(const int initial_state[ROW][COL])
{
	for (int i = 0; i < POP_SIZE; ++i)
	{
		Chromosome *temp = new Chromosome(initial_state);
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
	//int row = rand() % 9;
	int mutation[9];
	int pct = rand() % 100;
	for(int row=0; row<9;++row)
	{
		if (pct < 70)
		{
			int number[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			for (int j = 0; j < COL; ++j)
			{
				mutation[j] = first[row][j];
				if (first[row][j] != 0)
				{
					number[first[row][j] - 1] = 0;
				}
			}
			for (int j = 0; j < ROW; ++j)
			{
				//if the board is 0 that means that it is not a fix number
				if (mutation[j] == 0)
				{
					//this is to choose a number that is not in the row
					int x = rand() % 9;
					//this is where we keep finding a number that hasnt been used
					while (number[x] == 0)
					{
						x = rand() % 9;
					}
					//this is to add the number into the row
					mutation[j] = number[x];
					//this is showing that we used a number
					number[x] = 0;
				}
			}
			for (int j = 0; j < COL; ++j)
			{
				child_state[row][j] = mutation[j];
			}
		}
	}
}

//  While breeding, the parents have a chance of dying
bool Population::randomDeath(const int parent1, const int parent2)
{
	int pct = rand() % 100;
	int size = population.size();
	if(parent1==(size-1)||parent2==(size-1))
		return false;
	if(pct < 5)
	{
		if(population[parent1]&&population[parent2])
		{
			population.erase(population.begin() + parent1);
			population.erase(population.begin() + parent2);
		}
		return true;
	}
	return false;
}

//  Breeds two new children from the chosen parents, and adding them into the new population.
void Population::breed(const int parent1, const int parent2)
{
	//  While having breeding, the parents have a chance of dying
	if(randomDeath(parent1, parent2))
		return;

	int child1[ROW][COL];
	int child2[ROW][COL];

	//  Random cross section index [1-7]
	int cross = rand() % 8+1;//7 + 1;
	//  Determines which rows will be undergo crossover
	for (int i = 0; i < ROW; ++i)
	{
		//  Selected rows from both parents will be crossed over
		if (i < cross)
		{
			for (int j = 0; j < COL; ++j)
			{
				child1[i][j] = population[parent1]->board[i][j];
				child2[i][j] = population[parent2]->board[i][j];
			}
		}
		else
		{
			for (int j = 0; j < COL; ++j)
			{
				child1[i][j] = population[parent2]->board[i][j];
				child2[i][j] = population[parent1]->board[i][j];
			}
		}
	}

	//  There a probability that the childrens gene will mutate randomly
	mutatePct(child1);
	mutatePct(child2);

	Chromosome *temp1 = new Chromosome(child1);
	population.push_back(temp1);

	Chromosome *temp2 = new Chromosome(child2);
	population.push_back(temp2);
}
bool compare(const Chromosome *arg1, const Chromosome *arg2)
{
	return arg1->fitness_score > arg2->fitness_score;
}

int Population::solve(const int initial[ROW][COL])
{
	int parent1, parent2;
	int pop_size;
	
	//bool flag;

	int gen_count = 1;
	do
	{

		//  Sorting population from highest to lowest fitness score
		sort(population.begin(), population.end(), compare);

		//  Checks if the population is in a solved state (TBD)
		//flag = checkSolved();

		//  Removes the least fittest 50% from the popultion
		for (int i = 0; i < POP_SIZE / 5; ++i)
		{
			population.pop_back();
		}

		//  Choose parents and breeds, repopulating the population until the
		//  population is back to its original size
		do
		{
			int total = totalFit();
			//cout << "totalfitness: " << total << endl;
			parent1 = chooseParent(total);
			parent2 = chooseParent(total);
			//cout << "parent 1: " << parent1 << endl;
			//cout << "parent 2: " << parent2 << endl;
			breed(parent1, parent2);
			pop_size = population.size();


		} while (pop_size < POP_SIZE);

		cout << "Average Fitness: " << averageFitness() << endl;
		++gen_count;

		//while(gen_count < GEN_SIZE && flag == false);
	} while (gen_count < GEN_SIZE);

	generations = gen_count;
	cout << generations << endl;
	return 0;
}

int Population::totalFit()
{
	int total = 0;
	int size = population.size();
	for (int i = 0; i < size; ++i)
	{
		total += population[i]->fitness_score;
	}
	return total;
}

int Population::averageFitness()
{
	int total = 0;
	int size = population.size();
	for(int i = 0; i< size; ++i)
		total += population[i]->fitness_score;
	return (total/size);

}

int Population::chooseParent(int total)
{
	int random = rand() % total;
	int i = 0;
	while (random >= 0)
	{
		random -= population[i]->fitness_score;
		if (random <= 0)
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

void Population::copy(const int state[ROW][COL])
{
	for (int i = 0; i < COL; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			first[i][j] = state[i][j];
		}
	}
} 
