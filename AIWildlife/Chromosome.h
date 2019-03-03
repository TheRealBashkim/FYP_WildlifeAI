#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include "Structures.h"

class Chromosome
{
public:
	Chromosome();
	~Chromosome();
	std::vector<Gene*> GetChromosome() { return mChromosome;}
	void SetChromosome(std::vector<Gene*> chromosome) { this->mChromosome = chromosome; }
private:
	std::vector<Gene*> mChromosome;

};
#endif


