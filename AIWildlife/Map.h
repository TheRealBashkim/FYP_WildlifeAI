#ifndef MAP_H
#define MAP_H
#include <SDL.h>
#include <iostream>
#include "Texture2D.h"
#include "Tile.h"
#include "TinyXML/tinyxml.h"
#include <vector>

class Map
{
public:
	Map(SDL_Renderer * renderer);
	~Map();
	void AddTile(std::string path, int ID);
	void DrawMap();
	inline void SetMap(int ** Map) { this->mMap = Map; }
private:
	std::vector<Tile*> * mTiles = new std::vector<Tile*>();
	SDL_Rect mSrc, mDest;
	SDL_Renderer * mRenderer;
	int ** mMap;

};
#endif


