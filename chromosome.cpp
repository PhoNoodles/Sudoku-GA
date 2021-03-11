#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome()
{
	readIn();//read in from file
	fillBoard();//fill up the rest of the board
	fitness_score = fitnessEval();
}
void Chromosome::printState()
{

}

void Chromosome::readIn()
{

}
void Chromosome::fillBoard()
{
}

int Chromosome::fitnessEval()
{
	return 1;

}
