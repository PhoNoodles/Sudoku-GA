#include "population.h"
#include "chromosome.h"
int POP_SIZE = 500;
int GEN_SIZE = 1000;


Population::Population()
{
	for(int i=0;i<POP_SIZE;++i)
	{
		Chromosome * temp = new Chromosome();
		population.clear();
	}
	generations=0;
}

Population::~Population()
{
	population.clear();
	generations=0;

}
