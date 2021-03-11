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
	int fitness=216;
	int already_checked=[1,2,3,4,5,6,7,8,9];
	

	//Loop for each row 
	for(int i=0;i<81;i+=9)
	{
		//original number	
		for(int j=0;j<9;++j)
		{
			//check for duplicate
			for(int k=1;k<9;++k)
			{
				if(state[j+i]==state[k+i])
					--fitness;
			}
		}
	}


}
