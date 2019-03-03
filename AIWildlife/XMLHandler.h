#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "TinyXML/tinyxml.h"
#include "Structures.h"
class XMLHandler
{
public:
	static int ** LoadMapFromXML(std::string path);

	//Genetic Algorithms 
	static void StoreGenes(std::string path,std::vector<Gene*> genes);
	std::vector<Gene*> LoadChromosome(std::string path);



};
#endif


