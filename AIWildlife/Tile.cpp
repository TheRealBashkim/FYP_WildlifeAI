#include "Tile.h"



Tile::Tile(SDL_Texture * Texture,int ID)
{
	this->mTexture = Texture;
	this->mID = ID;
}


Tile::~Tile()
{
}
