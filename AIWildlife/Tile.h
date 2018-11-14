#ifndef TILE_H
#define TILE_H
#include "SDL.h"

class Tile
{
public:
	Tile(SDL_Texture * texture,int ID);
	inline SDL_Texture * GetTexture() { return this->mTexture; }
	inline int GetID() { return this->mID; }
	~Tile();

private:
	SDL_Texture * mTexture = nullptr;
	int mID = 0;
};
#endif


