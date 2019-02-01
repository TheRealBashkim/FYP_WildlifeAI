#include "Plant.h"



Plant::Plant(SDL_Renderer * renderer)
{
	this->mRenderer = renderer;
	mTexture = new Texture2D(mRenderer);
}

Plant::~Plant()
{
}

void Plant::LoadTexture(std::string path)
{
	mTexture->LoadFromFile(path);
}

void Plant::GeneratePosition()
{
	int x, y;
	x = std::rand() % 700;
	y = std::rand() % 700;
	mPosition->x = x;
	mPosition->y = y;
}

void Plant::SetPosition(Vector2D* setPosition)
{
	this->mPosition = setPosition;
}

void Plant::Draw()
{
	mTexture->Render(*mPosition);
}
