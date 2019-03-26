#ifndef CHROMOSOMEMANAGER_H
#define CHROMOSOMEMANAGER_H
#include "Chromosome.h"
#include "Structures.h"
#include "XMLHandler.h"
#include <vector>
#include "BaseAgent.h"

class BaseAgent;

class ChromosomeManager
{
public:
	ChromosomeManager();
	~ChromosomeManager();
	static BaseAgent * GenerateNewAgent(BaseAgent * m1, BaseAgent * m2);
	static Gene * GenerateGene();

private:
	static Gene * Crossover(Gene* parent1, Gene*parent2);
	static Gene * Mutation(Gene * tempCrossoverGene);
	
};

#endif

