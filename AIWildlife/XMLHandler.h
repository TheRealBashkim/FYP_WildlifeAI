#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "TinyXML/tinyxml.h"
#include "Structures.h"
#include "Chromosome.h"
class XMLHandler
{
public:
	static int ** LoadMapFromXML(std::string path);

	//Genetic Algorithms 
	static void StoreGenes(std::vector<Chromosome*> genes);
	static std::vector<Chromosome*> LoadChromosome(std::string path);
	static void AddGene(std::string path, Gene * gene);



};
#endif


