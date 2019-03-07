#ifndef CHROMOSOMEMANAGER_H
#define CHROMOSOMEMANAGER_H
#include "Chromosome.h"
#include "Structures.h"
#include "XMLHandler.h"
#include <vector>
class ChromosomeManager
{
public:
	ChromosomeManager();
	~ChromosomeManager();
	void SetChromosomeList(std::vector<Chromosome*> mChromoList) { this->mChromosomes = mChromoList; }
	void GenerateChromosome();

private:
	std::vector<Chromosome*> mChromosomes;
	
};

#endif

