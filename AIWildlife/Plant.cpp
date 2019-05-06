#include "Plant.h"



Plant::Plant(SDL_Renderer * renderer)
{
	//this->mRenderer = renderer;
	mTexture = new Texture2D(renderer);
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
	mSpawnTime = RandomFloat(0.2f, 0.5f);
}

void Plant::SetPosition(Vector2D* setPosition)
{
	this->mPosition = setPosition;
}

void Plant::Draw()
{
	if (mSpawned == true)
	{
		mTexture->Render(*mPosition);
	}
}

void Plant::Update(float dt)
{
	if (mTimer >= mSpawnTime)
	{
		mSpawned = true;
		mTimer = 0;
	}
	else
	{
		mTimer += dt;
	}
}

Vector2D Plant::GetCenter()
{
	Vector2D temp = Vector2D(mPosition->x + (mTexture->GetWidth()*0.5), mPosition->y + (mTexture->GetHeight())*0.5);
	return temp;
}
