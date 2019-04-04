#ifndef CHROMOSOMEMANAGER_H
#define CHROMOSOMEMANAGER_H
#include "Chromosome.h"
#include "Structures.h"
#include "XMLHandler.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <memory>
#include <functional>
#include "BaseAgent.h"
#include <stdlib.h>
#include <time.h>
class BaseAgent;

class ChromosomeManager
{
public:
	ChromosomeManager();
	~ChromosomeManager();
	static BaseAgent * GenerateNewAgent(BaseAgent * m1, BaseAgent * m2);
	static Gene * GenerateGene();
	static float GenerateFitnessOfChromosome(Gene * gene);

private:
	static Gene * Crossover(Gene* parent1, Gene*parent2);
	static Gene * Mutation(Gene * tempCrossoverGene);
	
};

#endif

