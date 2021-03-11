#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome(const int initial_state[ROW][COL])
{
	fillBoard();//fill up the rest of the board
	fitness_score = fitnessEval();
}
void Chromosome::printState()
{

}

void Chromosome::fillBoard()
{

}

int Chromosome::fitnessEval()
{
	return 1;

}
