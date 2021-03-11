#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome()
{
	state = makeState();
	fitness_score = fitnessEval();
}

Chromosome::Chromosome(string newState)
{
	state = newState;
	fitness_score = fitnessEval();
}

void Chromosome::printState()
{
	cout << state << endl;
}

string Chromosome::makeState()
{
	string temp;
	int digit;
	srand(time(NULL));
	
	for(int i = 0; i<8; ++i)
	{
		digit = rand () %9+1;
		temp += to_string(digit);
	}
	
	return temp;
}

int Chromosome::fitnessEval()
{
	return 1;

}
