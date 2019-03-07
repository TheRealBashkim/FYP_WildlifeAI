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
	static void StoreGenes(std::string path,std::vector<Chromosome*> genes);
	std::vector<Chromosome*> LoadChromosome(std::string path);



};
#endif


