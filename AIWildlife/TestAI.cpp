#include "TestAI.h"



TestAI::TestAI(SDL_Renderer * Renderer) : BaseAgent(Renderer)
{
}


TestAI::~TestAI()
{
}

void TestAI::Update(float dt, SDL_Event e)
{
	int x, y;
	if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		SDL_GetMouseState(&x, &y);
		temp = Vector2D(x, y);
		
	}
	mForce += Arrive(temp);
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

Vector2D TestAI::GetPosition()
{
	Vector2D temp(BaseAgent::GetPosition());
	return temp;
}

Vector2D TestAI::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D TestAI::Flee(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(GetCenter() - TargetPosition) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D TestAI::Arrive(Vector2D TargetPosition)
{
	Vector2D ToTarget = TargetPosition - GetCenter();
	double distance = ToTarget.Length();
	if(distance > 0)
	{
		const double DecTweaker = 5.0;
		double speed = distance / ((double)0.2 * DecTweaker);
		speed = std::min(speed, mMaxSpeed);
		Vector2D DesiredVel = ToTarget * speed / distance;
		return (DesiredVel - mVelocity);
	}
	return GetPosition();
}
