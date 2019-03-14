#ifndef CHROMOSOMEMANAGER_H
#define CHROMOSOMEMANAGER_H
#include "Chromosome.h"
#include "Structures.h"
#include "XMLHandler.h"
#include <vector>
#include "BaseAgent.h"

class ChromosomeManager
{
public:
	ChromosomeManager();
	~ChromosomeManager();
	static BaseAgent * CreateNewAgent(BaseAgent* m1, BaseAgent* m2);

private:
	
	
};

#endif

