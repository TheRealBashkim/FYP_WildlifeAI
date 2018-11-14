#ifndef TILE_H
#define TILE_H
#include "SDL.h"
#include "Texture2D.h"

class Tile
{
public:
	Tile(Texture2D * texture,int ID);
	inline Texture2D * GetTexture() { return this->mTexture; }
	inline int GetID() { return this->mID; }
	~Tile();

private:
	Texture2D * mTexture = nullptr;
	int mID = 0;
};
#endif


