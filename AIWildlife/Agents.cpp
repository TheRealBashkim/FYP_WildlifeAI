#include "Agents.h"
#include <ctime>


Agents::Agents(std::string name,SDL_Renderer * Renderer) : BaseAgent(Renderer)
{
	mName = name;
}


Agents::~Agents()
{
}

void Agents::Update(float dt, SDL_Event e)
{
	
	counter++;
	int x, y;
	if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		SDL_GetMouseState(&x, &y);
		temp = Vector2D(x, y);
		
		
	}
	if (counter > 4)
	{
		mForce += Wander(dt);
		counter = 0;
	}
	mForce += WallAvoidance();
	BaseAgent::Update(dt);
}

void Agents::Update(float dt)
{
	mForce += WallAvoidance();
	BaseAgent::Update(dt);
}

void Agents::Render()
{
	BaseAgent::Render();
	DrawFeelers();
}

void Agents::LoadTexture(std::string path)
{
	BaseAgent::LoadTexture(path);
}

void Agents::DrawFeelers()
{

	DebugLine(GetCenter(), GetCenter() + mVelocity, 255, 0, 0);
	DebugCircle(GetCenter() + mHeading * 70, 25, 255, 0, 0);
	if(mSelected)
	{
		Vector2D Reverse(GetPosition().x + mWidth, GetPosition().y + mHeight);
		//top
		DebugLine(GetPosition(), Vector2D(GetPosition().x + mWidth, GetPosition().y), 0, 0, 255);
		//left
		DebugLine(GetPosition(), Vector2D(GetPosition().x, GetPosition().y + mHeight), 0, 0, 255);
		DebugLine(GetPosition(), Reverse, 0, 0, 255);
		DebugLine(Vector2D(GetPosition().x, GetPosition().y + mHeight), Vector2D(Reverse.x, Reverse.y - mHeight), 0, 0, 255);
		//right
		DebugLine(Reverse,Vector2D(Reverse.x - mWidth,Reverse.y), 0, 0, 255);
		//bottom
		DebugLine(Reverse, Vector2D(Reverse.x, Reverse.y - mHeight), 0, 0, 255);
		mSelected = false;
	}
}

Vector2D Agents::GetPosition()
{
	Vector2D temp(BaseAgent::GetPosition());
	return temp;
}

Vector2D Agents::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D Agents::Flee(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(GetCenter() - TargetPosition) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D Agents::Arrive(Vector2D TargetPosition)
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

Vector2D Agents::Wander(float dt)
{
	Vector2D mForwardHeading = mHeading * 70;

	float minx, miny, maxx, maxy;
	miny = mForwardHeading.y - 2000;
	maxy = mForwardHeading.y + 2000;
	maxx = mForwardHeading.x + 2000;
	minx = mForwardHeading.x - 2000;

	float rangex = rand()%(int)(maxx - minx + 1) + minx;
	float rangey = rand()% (int)(maxy - miny + 1) + miny;
	Vector2D tempVector(rangex,rangey);
	return tempVector;
}

Vector2D Agents::WallAvoidance()
{
	Vector2D mHeadingPoint = mPosition;
	Vector2D OppositeForce;
	if(mHeadingPoint.x < 0)
	{
		OppositeForce.x = mForce.GetReverse().x + 300;
	}
	else if(mHeadingPoint.x > 840)
	{
		OppositeForce.x = mForce.GetReverse().x -300;
	}
	if (mHeadingPoint.y < 0)
	{
		OppositeForce.y = mForce.GetReverse().y + 300;
	}
	else if(mHeadingPoint.y > 840)
	{
		OppositeForce.y = mForce.GetReverse().y - 300;
	}

	return OppositeForce;
}
