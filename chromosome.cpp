#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome(const int initial_state[ROW][COL])
{
	fillBoard();//fill up the rest of the board
	fitness_score = fitnessEval();
}
void Chromosome::printState()
{
	for(int i = 0; i < COL; ++i)
	{
		for(int j = 0; j < ROW; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void Chromosome::fillBoard()
{
	for(int i = 0; i < COL ; ++i)//this is to go through each row
	{
		//this section is to see what number is already in the row 
		int number[1,2,3,4,5,6,7,8,9];
		for(int j = 0; j < ROW; ++j)
		{
			//this is to mark what is already in the row
			if(board[i][j] != 0)
			{
				number[board[i][j]+1] = 0; 
			}
		}
		//this is where we start filling in the row
		for(int j = 0; j < ROW; ++j)
		{
			//if the board is 0 that means that it is not a fix number
			if(board[i][j] == 0)
			{
				//this is to choose a number that is not in the row
				int x = rand() % 8;
				//this is where we keep finding a number that hasnt been used
				while(number[x] == 0)
				{
					rand() % 8; 
				}
				//this is to add the number into the row
				board[i][j] = number[x];
				//this is showing that we used a number 
				number[x] = 0;
			}
		}
	}

}

int Chromosome::fitnessEval()
{
	int fitness=216;
	int already_checked[1,2,3,4,5,6,7,8,9];
	

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
