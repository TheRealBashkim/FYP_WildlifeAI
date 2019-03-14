#ifndef BASEAGENT_H
#define BASEAGENT_H
#include "SDL.h"
#include "Commons.h"
#include "Texture2D.h"
#include "C2DMatrix.h"
#include "AgentManager.h"
#include <iostream>
#include "Chromosome.h"


class BaseAgent
{
public:
	BaseAgent(SDL_Renderer * Renderer);
	~BaseAgent();
	// Update and render functions
	virtual void Update(float dt);
	virtual void Render();
	void DrawFeelers();

	void LoadTexture(std::string path);

	Vector2D GetPosition() { return mPosition; }
	float GetWidth() { return mTexture->GetWidth(); }
	float GetHeight() { return mTexture->GetHeight(); }

	std::string GetName() { return mName; }

	float GetStamina() { return mStamina; }
	void SetStamina(float stamina) { mStamina = stamina; }

	float GetHealth() { return mHealth; }

	bool GetSelected() { return mSelected; }
	void SetSelected(bool selected) { mSelected = selected; }

	Vector2D GetHeading() { return mHeading; }

	float GetAge() { return mAge; }

	Vector2D GetCenter();
	SDL_Renderer * GetRenderer() { return mRenderer; }
	float GetFOVLength() { return mFOVLength; }

	void SetMaxAge(float age) { this->mMaxAge = age; }
	float GetMaxAge() { return this->mMaxAge; }
	void SetChromosome(Chromosome * Chromosome) { this->mChromosome = Chromosome;}
	Chromosome * GetChromosome() { return this->mChromosome;  }
	void SetStats();





protected:

	/**
	 * Character Attributes
	 */
	float mHealth = 100.0f;
	float mStamina = 1000.0f;

	Chromosome * mChromosome;

	float mNexGenerationWait = 2000;
	float mNexGenerationCounter = 0;
	bool mGenerationMade = false;


	void CheckForNewAgents();




	void DebugCircle(Vector2D centerPoint, double rad, int r, int g, int b);
	void DebugLine(Vector2D startPoint, Vector2D endPoint, int r, int g, int b);
	void SetPosition(Vector2D position) { this->mPosition = position; }

	SDL_Renderer * mRenderer;
	Texture2D * mTexture = nullptr;

	float mWidth = 0;
	float mHeight = 0;

	//Vehicle Model
	Vector2D mForce;
	Vector2D mVelocity;
	Vector2D mPosition;
	Vector2D mHeading;
	Vector2D mSide;
	double mSpeed;
	double mMaxSpeed;
	double mMaxForce;
	float counter = 0;
	std::string mName;
	bool mSelected = false;
	float mAge = 0;
	float mMaxAge = 100;

	float mFOVLength = 250;
	std::vector<BaseAgent*> mAgentsICanSee;

private:
	void IncrementAge(float dt);


	



};
#endif

