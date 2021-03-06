#include "HerbivoreAgent.h"



HerbivoreAgent::HerbivoreAgent(std::string name,SDL_Renderer * Renderer) : BaseAgent(Renderer)
{
	this->mName = name;
}


HerbivoreAgent::~HerbivoreAgent()
{
}
void HerbivoreAgent::Update(float dt)
{
	//counter++;
	if (counter > 20)
	{
		/*mForce += Wander(dt);*/
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

void HerbivoreAgent::Render()
{
	BaseAgent::Render();
	//DrawFeelers();
}

void HerbivoreAgent::PickOption(float dt)
{
	if (mSelectedOption == nullptr)
	{
		mSelectedOption = new AgentNetworkOptions();
		mSelectedOption->Option = WANDER;
	}
	if (mSelectedOption->Option == WANDER)
	{
		mForce += Wander(dt);
	}
	else if (mSelectedOption->Option == FEED)
	{
		if (mPlantsIcanSee.size() > 0)
		{
			mForce += Seek(*mPlantsIcanSee.at(0)->GetPosition());
		}
	}
	else if (mSelectedOption->Option == EVOLVE)
	{
		if (mChromosome->GetGene()->mGender == "Female")
		{
			if (mAlliesICanSee.size() > 0)
			{
				mForce += Seek(mAlliesICanSee.at(0)->GetPosition());
			}
			CheckForNewAgents();
		}
	}
	else if (mSelectedOption->Option == HIDE)
	{
		if (mEnemiesICanSee.size() > 0)
		{
			mForce += Flee(mEnemiesICanSee.at(0)->GetPosition());
		}
	}
}

void HerbivoreAgent::LoadTexture(std::string path)
{
	BaseAgent::LoadTexture(path);
}
void HerbivoreAgent::GetVisiblePlants(std::vector<Plant*> mPlants)
{
	std::vector<Plant*> visiblePlants;
	for (size_t i = 0; i < mPlants.size(); i++)
	{
		Vector2D heading = GetHeading();
		heading.Normalize();
		Vector2D totarget = GetCenter() - mPlants.at(i)->GetCenter();
		double totargetlength = totarget.Length();
		if (totargetlength < GetFOVLength())
		{
			totarget.Normalize();
			double dotproduct = heading.Dot(totarget);
			if (dotproduct > 0.85)
			{
				visiblePlants.push_back(mPlants.at(i));
			}
		}
	}
	mPlantsIcanSee = visiblePlants;
}
void HerbivoreAgent::NeuralInput()
{
	std::vector<float> mInputs;
	float mWanderStat = 0.0f;
	float mStaminaStat = 0.0f;
	float mEvolveStat = 0.0f;
	float mHideStat = 0.0f;

	if (mChromosome->GetGene()->mCurrentStamina < 30)
	{
		mStaminaStat += 0.75f;
	}
	//mEnemyStat += mAgentsICanSee.size() * 0.5;
	if (mChromosome->GetGene()->mCurrentAge > 18 && mAlliesICanSee.size() > 0 && mGenerationMade == false)
	{
		mEvolveStat += mAlliesICanSee.size() * 0.75f;
	}
	if (mEnemiesICanSee.size() > 0)
	{
		mHideStat += mEnemiesICanSee.size() * 0.50f;
	}

	//Wander
	mInputs.push_back(mWanderStat);
	//Feed
	mInputs.push_back(mStaminaStat);
	//Evolve
	mInputs.push_back(mEvolveStat);
	//Hide
	mInputs.push_back(mHideStat);
	mNetwork->Input(mInputs);
	mSelectedOption = mNetwork->Output();

}
Vector2D HerbivoreAgent::GetPosition()
{
	Vector2D temp(BaseAgent::GetPosition());
	return temp;
}

Vector2D HerbivoreAgent::Seek(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(TargetPosition - GetCenter()) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D HerbivoreAgent::Flee(Vector2D TargetPosition)
{
	Vector2D DesiredVelocity = Vec2DNormalize(GetCenter() - TargetPosition) * mMaxSpeed;
	return (DesiredVelocity - mVelocity);
}

Vector2D HerbivoreAgent::Arrive(Vector2D TargetPosition)
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

Vector2D HerbivoreAgent::Wander(float dt)
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

Vector2D HerbivoreAgent::WallAvoidance()
{
	Vector2D mHeadingPoint = mPosition;
	Vector2D OppositeForce;
	if (mHeadingPoint.x < 0)
	{
		OppositeForce.x = mForce.GetReverse().x + 300;
	}
	else if (mHeadingPoint.x > 840)
	{
		OppositeForce.x = mForce.GetReverse().x - 300;
	}
	if (mHeadingPoint.y < 0)
	{
		OppositeForce.y = mForce.GetReverse().y + 300;
	}
	else if (mHeadingPoint.y > 840)
	{
		OppositeForce.y = mForce.GetReverse().y - 300;
	}

	return OppositeForce;
}

