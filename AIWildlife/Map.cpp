#include "Map.h"
#include "Commons.h"


Map::Map(SDL_Renderer * renderer)
{
	this->mRenderer = renderer;
	mMap = new int*[MapRow];
	for(int i = 0; i < MapRow;i++)
	{
		mMap[i] = new int[MapColumn];
	}
	mSrc.x = mSrc.y = 0;
	mSrc.w = mDest.w = TileSize;
	mSrc.h = mDest.h = TileSize;
	mDest.x = mDest.y = 0;
}



Map::~Map()
{
	if(mMap != nullptr)
	{
		mMap = nullptr;
	}
	if(!mTiles->empty())
	{
		mTiles->clear();
	}
	mTiles = nullptr;
}

void Map::AddTile(std::string path, int ID)
{
	Texture2D * tempTexture = new Texture2D(mRenderer);
	tempTexture->LoadFromFile(path);
	Tile * tile = new Tile(tempTexture,ID);
	mTiles->push_back(tile);
}

void Map::DrawMap()
{
	int ID = 0;
	for (int row = 0; row < MapRow; row++)
	{
		for (int column = 0; column < MapColumn; column++)
		{
			ID = mMap[row][column];
			mDest.x = column * TileSize;
			mDest.y = row * TileSize;
			for (int i = 0; i < mTiles->size(); i++)
			{
				if (ID == mTiles->at(i)->GetID())
				{
					mTiles->at(i)->GetTexture()->Render(mSrc, mDest);
					//TextureManager::Draw(mTiles->at(i)->GetTexture(), mRenderer, mSrc, mDest);
				}
			}
		}
	}
}
