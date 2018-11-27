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
	BaseAgent::Update(dt);
}

void TestAI::Render()
{
	
	BaseAgent::Render();
	DrawFeelers();
}

void TestAI::DrawFeelers()
{
	DebugLine(GetCenter(), GetCenter() + mHeading * 5, 255, 0, 0);
}

Vector2D TestAI::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}
