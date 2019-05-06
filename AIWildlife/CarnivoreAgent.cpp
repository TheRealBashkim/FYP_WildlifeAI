#include "CarnivoreAgent.h"



CarnivoreAgent::CarnivoreAgent(std::string name,SDL_Renderer * Renderer) : BaseAgent(Renderer)
{
	this->mName = name;
}


CarnivoreAgent::~CarnivoreAgent()
{
}


void CarnivoreAgent::Update(float dt)
{
	//NeuralInput();
	//if (mChromosome->GetGene()->mCurrentStamina < 100 && !mAgentsICanSee.empty())
	//{
	//	TargetEnemy(dt);
	//}
	 if (counter > 4)
	{
		//mForce += Wander(dt);
		 NeuralInput();
		counter = 0;
	}
	else
	{
		counter++;
	}
	 PickOption(dt);
	mForce += WallAvoidance();
	
	BaseAgent::Update(dt);
}

void CarnivoreAgent::Render()
{
	BaseAgent::Render();
	//DrawFeelers();
}

void CarnivoreAgent::PickOption(float dt)
{
	if (mSelectedOption->Option == WANDER)
	{
		mForce += Wander(dt);
	}
	else if (mSelectedOption->Option == FEED)
	{
		for (int i = 0; i < mEnemiesICanSee.size(); i++)
		{
			mForce += Seek(mEnemiesICanSee.at(i)->GetPosition());
		}
	}
	else if (mSelectedOption->Option == EVOLVE)
	{
		if (mChromosome->GetGene()->mGender == "Female")
		{
			if(mAlliesICanSee.size() > 0)
			{
				mForce += Seek(mAlliesICanSee.at(0)->GetPosition());
			}
			CheckForNewAgents();
		}
	}
	else if (mSelectedOption->Option == HIDE)
	{
		mForce += Wander(dt);
	}
}

void CarnivoreAgent::LoadTexture(std::string path)
{
	BaseAgent::LoadTexture(path);
}
void CarnivoreAgent::TargetEnemy(float dt)
{
	Vector2D * tempPos;
	for (int i = 0; i < mAgentsICanSee.size(); i++)
	{
		if (mAgentsICanSee.at(i)->GetName() != GetName())
		{
			Seek(mAgentsICanSee.at(i)->GetPosition());
		}
		if (BoxToBox(mPosition, mWidth, mHeight, mAgentsICanSee.at(i)->GetPosition(), mAgentsICanSee.at(i)->GetWidth(), mAgentsICanSee.at(i)->GetHeight()))
		{
			mAgentsICanSee.at(i)->GetChromosome()->GetGene()->health -= 40;
			mChromosome->GetGene()->mCurrentStamina += 40;
		}
	}
}
void CarnivoreAgent::NeuralInput()
{
	std::vector<float> mInputs;
	float mWanderStat = 1.00f;
	float mStaminaStat = 0;
	float mEnemyStat = 0;
	float mEvolveStat = 0;

	if (mChromosome->GetGene()->mCurrentStamina < 30)
	{
		mStaminaStat += 0.75f;
	}
	else if (mChromosome->GetGene()->mCurrentStamina > 30 && mChromosome->GetGene()->mCurrentStamina < 70)
	{
		mStaminaStat += 0.50f;
	}
	else if (mChromosome->GetGene()->mCurrentStamina > 71)
	{
		mStaminaStat += 0.25f;
	}
	//mEnemyStat += mAgentsICanSee.size() * 0.5;
	if (mChromosome->GetGene()->mCurrentAge > 18 && mAlliesICanSee.size() > 0 && mGenerationMade == false)
	{
		mEvolveStat += mAlliesICanSee.size() * 0.50f;
	}
	//Wander
	mInputs.push_back(mWanderStat);
	//Feed
	mInputs.push_back(mStaminaStat);
	//Evolve
	mInputs.push_back(mEvolveStat);
	//Hide
	mInputs.push_back(0.0f);
	mNetwork->Input(mInputs);
	mSelectedOption = mNetwork->Output();
}
Vector2D CarnivoreAgent::GetPosition()
{
	Vector2D temp(BaseAgent::GetPosition());
	return temp;
}

Vector2D CarnivoreAgent::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D CarnivoreAgent::Flee(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(GetCenter() - TargetPosition) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D CarnivoreAgent::Arrive(Vector2D TargetPosition)
{
	Vector2D ToTarget = TargetPosition - GetCenter();
	double distance = ToTarget.Length();
	if (distance > 0)
	{
		const double DecTweaker = 5.0;
		double speed = distance / ((double)0.2 * DecTweaker);
		speed = std::min(speed, mMaxSpeed);
		Vector2D DesiredVel = ToTarget * speed / distance;
		return (DesiredVel - mVelocity);
	}
	return GetPosition();
}

Vector2D CarnivoreAgent::Wander(float dt)
{
	Vector2D mForwardHeading = mHeading * 70;

	float minx, miny, maxx, maxy;
	miny = mForwardHeading.y - 2000;
	maxy = mForwardHeading.y + 2000;
	maxx = mForwardHeading.x + 2000;
	minx = mForwardHeading.x - 2000;

	float rangex = rand() % (int)(maxx - minx + 1) + minx;
	float rangey = rand() % (int)(maxy - miny + 1) + miny;
	Vector2D tempVector(rangex, rangey);
	return tempVector;
}

Vector2D CarnivoreAgent::WallAvoidance()
{
	Vector2D mHeadingPoint = mPosition;
	Vector2D OppositeForce;
	if (mHeadingPoint.x < mWidth)
	{
		OppositeForce.x = mForce.GetReverse().x + 300;
	}
	else if (mHeadingPoint.x > 840 - mWidth)
	{
		OppositeForce.x = mForce.GetReverse().x - 300;
	}
	if (mHeadingPoint.y < mWidth)
	{
		OppositeForce.y = mForce.GetReverse().y + 300;
	}
	else if (mHeadingPoint.y > 840 - mHeight)
	{
		OppositeForce.y = mForce.GetReverse().y - 300;
	}

	return OppositeForce;
}
