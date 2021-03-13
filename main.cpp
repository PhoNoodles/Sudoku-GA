#include "chromosome.h"
#include "population.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

void readIn(char *file_name, int initial_state[ROW][COL])
{
    ifstream in_file(file_name);
    if(in_file.is_open() && in_file.good())
    {
        while(!in_file.eof())
        {
            for(int i = 0; i < ROW; ++i)
            {
                for(int j = 0; j < COL; ++j)
                {
                    in_file >> initial_state[i][j]; 
                }
            }
        }
        
        in_file.close();
    }
    else
        cout << "Failed to open file. " << endl;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int initial_state[ROW][COL];
    if(argc > 1)
    {
        readIn(argv[1], initial_state);
    }
    else
    {
        cout << "No file detected." << endl;
        return 0;
    }
    
    //  Test: Displays intial sudoku state
    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COL; ++j)
        {
            cout << initial_state[i][j];
        }
        cout << endl;
    }

    Population* initial = new Population(initial_state);
    initial->copy(initial_state);
    initial->solve(initial_state);

    return 0;
}
