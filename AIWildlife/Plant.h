#ifndef PLANT_H
#define PLANT_H
#include <SDL.h>
#include "Texture2D.h"

class Plant
{
public:
	Plant(SDL_Renderer * renderer);
	~Plant();
	void LoadTexture(std::string path);
	void GeneratePosition();
	void SetPosition(Vector2D * setPosition);
	void Draw();
	void SetStatIncrease(float stat) { this->mStamIncrease = stat; }
	float GetStatIncrease() { return mStamIncrease; }
	Vector2D * GetPosition() { return mPosition; }
	float GetWidth() { return mTexture->GetWidth(); }
	float GetHeight() { return mTexture->GetHeight(); }

private:
	SDL_Renderer * mRenderer;
	Texture2D * mTexture;
	float mStamIncrease = 0.0f;
	Vector2D * mPosition = new Vector2D(0, 0);
};

#endif


