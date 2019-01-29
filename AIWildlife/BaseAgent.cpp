#include "BaseAgent.h"

BaseAgent::BaseAgent(SDL_Renderer* Renderer)
{
	this->mRenderer = Renderer;
	this->mTexture = new Texture2D(mRenderer);
	mMaxSpeed = 100.0f;
	mMaxForce = 10.0f;
	mHeading = Vector2D(0.0f, -1.0f);
	mSide = Vector2D(1.0f, 0.0f);
}

BaseAgent::~BaseAgent()
{
}

void BaseAgent::Update(float dt)
{
	if (mStamina <= 0.0f)
	{
		return;
	}
	if (!mForce.isZero())
	{
		mStamina = mStamina - 0.01f;
	}
	mVelocity += mForce * dt;
	mVelocity.Truncate(mMaxSpeed);
	mPosition += mVelocity * dt;
	mHeading.x = mVelocity.x * 5;
	mHeading.y = mVelocity.y * 5;
	mHeading.Normalize();
	mSide = mHeading.Perp();
}
	

void BaseAgent::LoadTexture(std::string path)
{
	mTexture->LoadFromFile(path);
	mWidth = mTexture->GetWidth();
	mHeight = mTexture->GetHeight();
}

void BaseAgent::Render()
{
	mTexture->Render(mPosition);
}

Vector2D BaseAgent::GetCenter()
{
	Vector2D temp = Vector2D(mPosition.x + (mTexture->GetWidth()*0.5), mPosition.y + (mTexture->GetHeight())*0.5);
	return temp;
}

void BaseAgent::DebugCircle(Vector2D centerPoint, double rad, int r, int g, int b)
{
	Vector2D Vec(0.0f, rad);
	float stepSize = 0.02f;
	float t = (float)DegsToRads(360.0f);
	while(Vec.x < t)
	{
		Vector2D tempa(Vec.y * cosf(Vec.x), Vec.y * sinf(Vec.x));
		Vector2D tempb(centerPoint.x + tempa.x, centerPoint.y + tempa.y);
		SDL_SetRenderDrawColor(mRenderer, r, g, b, 255);
		SDL_RenderDrawPoint(mRenderer, (int)tempb.x, (int)tempb.y);
		Vec.x += stepSize;
	}
	
}

void BaseAgent::DebugLine(Vector2D startPoint, Vector2D endPoint, int r, int g, int b)
{
	SDL_SetRenderDrawColor(mRenderer, r, g, b, 255);
	SDL_RenderDrawLine(mRenderer, (int)startPoint.x, (int)startPoint.y, (int)endPoint.x, (int)endPoint.y);
}
