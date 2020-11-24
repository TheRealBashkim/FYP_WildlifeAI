#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include "Structures.h"

class Chromosome
{
public:
	Chromosome();
	~Chromosome();
	Gene* GetGene() { return mGene; }
	void SetGene(Gene* gene) { this->mGene = gene; }

private:
	Gene * mGene;

};
#endif


