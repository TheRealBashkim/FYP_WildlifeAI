#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "TinyXML/tinyxml.h"
class XMLHandler
{
public:
	static int ** LoadMapFromXML(std::string path);

};
#endif


