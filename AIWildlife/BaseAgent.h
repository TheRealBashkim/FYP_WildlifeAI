#ifndef BASEAGENT_H
#define BASEAGENT_H
#include "SDL.h"
#include "Commons.h"
#include "Texture2D.h"
#include <iostream>

class BaseAgent
{
public:
	BaseAgent(SDL_Renderer * Renderer);
	~BaseAgent();
	 void Update(float dt);
	 void Update(float dt, SDL_Event e);
	void LoadTexture(std::string path);
	void Render();
protected:
	Vector2D GetCenter();
	void DebugCircle(Vector2D centerPoint, double rad, int r, int g, int b);
	void DebugLine(Vector2D startPoint, Vector2D endPoint, int r, int g, int b);
	void SetPosition(Vector2D position) { this->mPosition = position; }

	SDL_Renderer * mRenderer;
	Texture2D * mTexture = nullptr;

	//Vehicle Model
	Vector2D mForce;
	Vector2D mVelocity;
	Vector2D mPosition;
	Vector2D mHeading;
	Vector2D mSide;
	double mSpeed;
	double mMaxSpeed;
	double mMaxForce;


	



};
#endif

