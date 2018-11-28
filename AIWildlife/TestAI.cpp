#include "TestAI.h"



TestAI::TestAI(SDL_Renderer * Renderer) : BaseAgent(Renderer)
{
}


TestAI::~TestAI()
{
}

void TestAI::Update(float dt, SDL_Event e)
{
	Vector2D temp = Vector2D();
	int x, y;
	if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		SDL_GetMouseState(&x, &y);
		temp = Vector2D(x, y);
		mForce += Seek(temp);
	}
	ObsticleAvoidance();
	BaseAgent::Update(dt);
}

void TestAI::Render()
{
	BaseAgent::Render();
	DrawFeelers();
}

void TestAI::LoadTexture(std::string path)
{
	BaseAgent::LoadTexture(path);
}

void TestAI::DrawFeelers()
{
	DebugLine(GetCenter(), GetCenter() + mVelocity, 255, 0, 0);
	DebugCircle(GetCenter() + mHeading * 70, 25, 255, 0, 0);
}

Vector2D TestAI::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

void TestAI::ObsticleAvoidance()
{
	if (mPosition.x > 874)
	{
		Vector2D temp(0, mPosition.y);
		mForce += Seek(temp);
	}
	else if (mPosition.x < 0)
	{
		Vector2D temp(875, mPosition.y);
		mForce += Seek(temp);
	}
	else if (mPosition.y > 874)
	{
		Vector2D temp(mPosition.x, 0);
		mForce += Seek(temp);
	}
	else if (mPosition.y < 0)
	{
		Vector2D temp(mPosition.x, 875);
		mForce += Seek(temp);
	}
}
