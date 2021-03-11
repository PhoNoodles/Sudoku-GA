#include "chromosome.h"
#include "population.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

void readIn(char *file_name, int initial_state[9][9])
{
    ifstream in_file(file_name);
    if(in_file.is_open() && in_file.good())
    {
        while(!in_file.eof())
        {
            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    in_file >> initial_state[i][j]; 
                }
            }
        }
    }
    else
        cout << "Failed to open file. " << endl;

    in_file.close();
}

int main(int argc, char *argv[])
{
    int initial_state[9][9];
    if(argc > 1)
    {
        readIn(argv[1], initial_state);
    }
    else
    {
        cout << "No file name detected." << endl;
        return 0;
    }

    //  Test: Displays intial sudoku state
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << initial_state[i][j];
        }
        cout << endl;
    }

    //Population* initial = new Population(initial_state);

    return 0;
}
