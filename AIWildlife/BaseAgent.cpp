#include "BaseAgent.h"
#include "ChromosomeManager.h"
#include "StatWindow.h"
#include "Messaging.h"

BaseAgent::BaseAgent(SDL_Renderer* Renderer)
{
	this->mRenderer = Renderer;
	this->mTexture = new Texture2D(mRenderer);
	mChromosome = new Chromosome();
	mMaxSpeed = 100.0f;
	mMaxForce = 10.0f;
	mNetwork = new NeuralNetwork();
	mSelectedOption = new AgentNetworkOptions();
	mSelectedOption->Option = WANDER;
	mHeading = Vector2D(0.0f, -1.0f);
	mSide = Vector2D(1.0f, 0.0f);
}

BaseAgent::~BaseAgent()
{
}

void BaseAgent::Update(float dt)
{
	
	mAgentsICanSee = AgentManager::Instance()->GetVisibleAgents(this);
	mAlliesICanSee = AgentManager::Instance()->GetVisibleAllies(this);
	mEnemiesICanSee = AgentManager::Instance()->GetVisibleEnemies(this);
	IncrementAge(dt);
	//mChromosome->GetGene()->mCurrentAge = mAge;
	if (mStamina <= 0.0f)
	{
		return;
	}
	if (!mForce.isZero())
	{
		//mStamina = mStamina - 0.01f;
		mChromosome->GetGene()->mCurrentStamina -= 0.01f;
	}
	const Vector2D acceleration = mForce / 1.0f;
	mVelocity += acceleration * dt;
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
	DrawFeelers();
}

void BaseAgent::DrawFeelers()
{
	DebugLine(GetCenter(), GetCenter() + mVelocity, 255, 0, 0);
	if (mSelected)
	{
		Vector2D Reverse(GetPosition().x + mWidth, GetPosition().y + mHeight);
		//top
		DebugLine(GetPosition(), Vector2D(GetPosition().x + mWidth, GetPosition().y), 0, 0, 255);
		//left
		DebugLine(GetPosition(), Vector2D(GetPosition().x, GetPosition().y + mHeight), 0, 0, 255);
		DebugLine(GetPosition(), Reverse, 0, 0, 255);
		DebugLine(Vector2D(GetPosition().x, GetPosition().y + mHeight), Vector2D(Reverse.x, Reverse.y - mHeight), 0, 0, 255);
		//right
		DebugLine(Reverse, Vector2D(Reverse.x - mWidth, Reverse.y), 0, 0, 255);
		//bottom
		DebugLine(Reverse, Vector2D(Reverse.x, Reverse.y - mHeight), 0, 0, 255);

		//FOV Lines
		Vector2D polarVec(0.0f, mFOVLength);
		Vector2D normalized = Vec2DNormalize(mHeading);
		Vector2D left;

		//Create point rotated to the left of heading.
		Vector2D leftPoint;
		leftPoint.x = (normalized.x * cos(0.85)) - (normalized.y * sin(0.85));
		leftPoint.y = (normalized.x * sin(0.85)) + (normalized.y * cos(0.85));

		//Create point rotated to the right of heading.
		Vector2D rightPoint;
		rightPoint.x = (normalized.x * cos(-0.85)) - (normalized.y * sin(-0.85));
		rightPoint.y = (normalized.x * sin(-0.85)) + (normalized.y * cos(-0.85));

		//Move the left point out from the centre of the tank to the distance set by mFOVLengthLength.
		Vector2D m_viewFrustumLeft;
		m_viewFrustumLeft.x = GetCenter().x + (leftPoint.x*mFOVLength);
		m_viewFrustumLeft.y = GetCenter().y + (leftPoint.y*mFOVLength);

		//Move the right point out from the centre of the tank to the distance set by mFOVLengthLength.
		Vector2D m_viewFrustumRight;
		m_viewFrustumRight.x = GetCenter().x + (rightPoint.x*mFOVLength);
		m_viewFrustumRight.y = GetCenter().y + (rightPoint.y*mFOVLength);

		//Draw the field of view frustum
		DebugLine(GetCenter(), m_viewFrustumRight, 255, 0, 0);
		DebugLine(GetCenter(), m_viewFrustumLeft, 255, 0, 0);

		if(!mAgentsICanSee.empty())
		{
			for(size_t i = 0; i < mAgentsICanSee.size();i++)
			{
				if(mAgentsICanSee[i]->GetName() == mName)
				{
					Vector2D Reverse(mAgentsICanSee[i]->GetPosition().x + mAgentsICanSee[i]->GetWidth(), mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight());

					//top
					DebugLine(mAgentsICanSee[i]->GetPosition(), Vector2D(mAgentsICanSee[i]->GetPosition().x + mAgentsICanSee[i]->GetWidth(), mAgentsICanSee[i]->GetPosition().y), 0, 255, 0);
					//left
					DebugLine(mAgentsICanSee[i]->GetPosition(), Vector2D(mAgentsICanSee[i]->GetPosition().x, mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight()), 0, 255, 0);
					DebugLine(mAgentsICanSee[i]->GetPosition(), Reverse, 0, 0, 255);
					DebugLine(Vector2D(mAgentsICanSee[i]->GetPosition().x, mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight()), Vector2D(Reverse.x, Reverse.y - mAgentsICanSee[i]->GetHeight()), 0, 255, 0);
					//right
					DebugLine(Reverse, Vector2D(Reverse.x - mAgentsICanSee[i]->GetWidth(), Reverse.y), 0, 255, 0);
					//bottom
					DebugLine(Reverse, Vector2D(Reverse.x, Reverse.y - mAgentsICanSee[i]->GetHeight()), 0, 255, 0);
				}
				else
				{
					Vector2D Reverse(mAgentsICanSee[i]->GetPosition().x + mAgentsICanSee[i]->GetWidth(), mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight());

					//top
					DebugLine(mAgentsICanSee[i]->GetPosition(), Vector2D(mAgentsICanSee[i]->GetPosition().x + mAgentsICanSee[i]->GetWidth(), mAgentsICanSee[i]->GetPosition().y), 255, 0, 0);
					//left
					DebugLine(mAgentsICanSee[i]->GetPosition(), Vector2D(mAgentsICanSee[i]->GetPosition().x, mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight()), 255, 0, 0);
					DebugLine(mAgentsICanSee[i]->GetPosition(), Reverse, 255, 0, 0);
					DebugLine(Vector2D(mAgentsICanSee[i]->GetPosition().x, mAgentsICanSee[i]->GetPosition().y + mAgentsICanSee[i]->GetHeight()), Vector2D(Reverse.x, Reverse.y - mAgentsICanSee[i]->GetHeight()), 255, 0, 0);
					//right
					DebugLine(Reverse, Vector2D(Reverse.x - mAgentsICanSee[i]->GetWidth(), Reverse.y), 255, 0, 0);
					//bottom
					DebugLine(Reverse, Vector2D(Reverse.x, Reverse.y - mAgentsICanSee[i]->GetHeight()), 255, 0, 0);
				}
				

			}
		}
		mSelected = false;
	}
}

Vector2D BaseAgent::GetCenter()
{
	Vector2D temp = Vector2D(mPosition.x + (mTexture->GetWidth()*0.5), mPosition.y + (mTexture->GetHeight())*0.5);
	return temp;
}

void BaseAgent::SetStats()
{
	mHealth = mChromosome->GetGene()->health;
	mMaxAge = mChromosome->GetGene()->maxAge;
	mMaxSpeed = mChromosome->GetGene()->maxSpeed;
	mChromosome->GetGene()->mCurrentStamina = mChromosome->GetGene()->maxStamina;
}

void BaseAgent::CheckForNewAgents()
{
	BaseAgent * mPicked = nullptr;

	if (mGenerationMade == true)
	{
		if (mNexGenerationCounter >= mNexGenerationWait)
		{
			mGenerationMade = false;
			mNexGenerationCounter = 0;
		}
		mNexGenerationCounter++;
		return;
	}
	//Need to back up average age of mating in research.
	if (mChromosome->GetGene()->mCurrentAge < 25)
	{
		return;
	}
	for (int i = 0; i < mAgentsICanSee.size(); i++)
	{
		if (mAgentsICanSee[i]->GetName() == GetName())
		{
			if (mAgentsICanSee[i]->GetChromosome()->GetGene()->mCurrentAge > 25)
			{
				if (mAgentsICanSee.at(i)->GetChromosome()->GetGene()->mGender == "Male")
				{
					mPicked = mAgentsICanSee[i];
				}
				break;
			}
		}
	}
	if (mPicked == nullptr)
	{
		return;
	}
	mGenerationMade = true;
	BaseAgent * newAgent = ChromosomeManager::GenerateNewAgent(this, mPicked);
	AgentManager::Instance()->AddAgent(newAgent);
	//Messaging::Initialize()->SendMessage("New Agent: " + newAgent->GetName());
}

void BaseAgent::PickOption(float dt)
{
}


	//Messaging::Initialize()->SendMessage("New Agent: " + newAgent->GetName());


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

void BaseAgent::IncrementAge(float dt)
{
	mChromosome->GetGene()->mCurrentAge += 0.0088f;
	//mAge = mAge + 0.016f;
}
