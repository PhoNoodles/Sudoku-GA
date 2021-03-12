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

	return;

}

int Chromosome::fitnessEval()
{
	int fitness=216;
	int row [9] = {0,0,0,0,0,0,0,0,0};
	int column [9] = {0,0,0,0,0,0,0,0,0};
	int subGrid [9] = {0,0,0,0,0,0,0,0,0};

	//Loop nine times 
	for(int i=0;i<9;++i)
	{
		//original number	
		for(int j=0;j<8;++j)
		{
			//check for duplicate in row
			for(int r=1;r<9;++r)
			{
				if(checkedAlready(row,board[i][j]))
					break;
				if(board[i][j]==board[i][r])
					--fitness;
			}

			//check for duplicate in columns
			for(int c=1;c<9;++c)
			{
				if(checkedAlready(column,board[j][i]))
					break;
				if(board[j][i]==board[c][i])
					--fitness;
			}

		}
		//reset the already checked already to all zeros
		for(int p=0;p<9;++p)
		{
			row[p]=0;
			column[p]=0;
		}
	}

	for(int r=0;r<7;r+=3)
	{
		for(int c=0;c<7;c+=3)
		{
			for(int c1=0;c1<3;++c1)
			{

				for(int c2=1;c2<3;c2++)
				{
					if(checkedAlready(subGrid,board[r][c1]))
						break;
					if(board[r][c+c1]==board[r][c+c2])
						--fitness;
				}
				if(board[r][c+c1]==board[r+1][c+c1])
					--fitness;
				if(board[r][c+c1]==board[r+2][c+c1])
					--fitness;

			}
			for(int p;p<9;++p)
				subGrid[p]=0;

		}
		for(int p;p<9;++p)
			subGrid[p]=0;

	}
	return fitness;

}

int Chromosome::checkedAlready(int array [],int num)
{	
	for(int i=0;i<9;++i)
	{
		if(num==array[i])
			return 1;
		if(array[i]==0)
		{
			array[i]=num;
			return 0;
		}
	}
	return 0;

}
