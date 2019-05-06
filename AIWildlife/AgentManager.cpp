#include "AgentManager.h"
#include "XMLHandler.h"


AgentManager * AgentManager::mInstance = nullptr;

AgentManager * AgentManager::Instance()
{
	if(mInstance == nullptr)
	{
		mInstance = new AgentManager();
	}
	return mInstance;
}

void AgentManager::SetRenderer(SDL_Renderer* Renderer)
{
	mRenderer = Renderer;
}


void AgentManager::Update(float dt)
{
	
	SavePeriodically();
	for(int i = 0; i < mAgents->size();i++)
	{
		// kills agent relating to old age
		if(mAgents->at(i)->GetChromosome()->GetGene()->mCurrentAge >= mAgents->at(i)->GetMaxAge() || mAgents->at(i)->GetChromosome()->GetGene()->mCurrentStamina <= 0)
		{
			KillAgents(i);
		}
		else
		{
			mAgents->at(i)->Update(dt);
		}
		
	}
}

void AgentManager::Draw()
{
	for(int i = 0; i < mAgents->size();i++)
	{
		mAgents->at(i)->Render();
	}
}

BaseAgent * AgentManager::CheckMousePolling(Vector2D mousepos)
{
	//int id = MaxInt;
	for (int i = 0; i < mAgents->size(); i++)
	{
		if (PointInBoxCollision(mousepos, mAgents->at(i)->GetPosition(), mAgents->at(i)->GetWidth(), mAgents->at(i)->GetHeight()))
		{
			return mAgents->at(i);
		}
	}
	return nullptr;

}

std::vector<BaseAgent*> AgentManager::GetVisibleAgents(BaseAgent* Looking)
{
	std::vector<BaseAgent*> VisibleAgents;

	for (size_t i = 0; i < mAgents->size(); i++)
	{
		if (mAgents->at(i) != Looking)
		{
			Vector2D heading = Looking->GetHeading();
			heading.Normalize();
			Vector2D vectotarget = mAgents->at(i)->GetCenter() - Looking->GetCenter();
			double totargetlength = vectotarget.Length();
			if (totargetlength < mAgents->at(i)->GetFOVLength())
			{
				vectotarget.Normalize();
				double dotProduct = heading.Dot(vectotarget);
				if (dotProduct > 0.85)
				{
					VisibleAgents.push_back(mAgents->at(i));
				}
			}
		}
	}
return VisibleAgents;
}
std::vector<BaseAgent*> AgentManager::GetVisibleAllies(BaseAgent * Looking)
{
	std::vector<BaseAgent*> VisibleAgents;

	for (size_t i = 0; i < mAgents->size(); i++)
	{
		if (mAgents->at(i) != Looking)
		{
			Vector2D heading = Looking->GetHeading();
			heading.Normalize();
			Vector2D vectotarget = mAgents->at(i)->GetCenter() - Looking->GetCenter();
			double totargetlength = vectotarget.Length();
			if (totargetlength < mAgents->at(i)->GetFOVLength())
			{
				vectotarget.Normalize();
				double dotProduct = heading.Dot(vectotarget);
				if (dotProduct > 0.85)
				{
					if (mAgents->at(i)->GetName() == Looking->GetName())
					{
						VisibleAgents.push_back(mAgents->at(i));
					}
				}
			}
		}
	}
	return VisibleAgents;
}
std::vector<BaseAgent*> AgentManager::GetVisibleEnemies(BaseAgent * Looking)
{
	std::vector<BaseAgent*> VisibleAgents;

	for (size_t i = 0; i < mAgents->size(); i++)
	{
		if (mAgents->at(i) != Looking)
		{
			Vector2D heading = Looking->GetHeading();
			heading.Normalize();
			Vector2D vectotarget = mAgents->at(i)->GetCenter() - Looking->GetCenter();
			double totargetlength = vectotarget.Length();
			if (totargetlength < mAgents->at(i)->GetFOVLength())
			{
				vectotarget.Normalize();
				double dotProduct = heading.Dot(vectotarget);
				if (dotProduct > 0.85)
				{
					if (mAgents->at(i)->GetName() != Looking->GetName())
					{
						VisibleAgents.push_back(mAgents->at(i));
					}
				}
			}
		}
	}
	return VisibleAgents;
}
void AgentManager::SavePeriodically()
{
	if (mPeriodWait >= 2000)
	{
		std::vector<Chromosome*>* tempchromos = new std::vector<Chromosome*>();
		for (int i = 0; i < mAgents->size();i++)
		{
			tempchromos->push_back(mAgents->at(i)->GetChromosome());
		}
		XMLHandler::StoreGenes(*tempchromos);
		mPeriodWait = 0;
		return;
	}
	mPeriodWait++;
}


void AgentManager::KillAgents(int index)
{
	//std::vector<Chromosome*> mChromosome = XMLHandler::LoadChromosome("Chromosome.xml");
	//for(int i = 0; i < mChromosome.size();i++)
	//{
	//	if(mChromosome[i]->GetGene()->mID == mAgents->at(i)->GetChromosome()->GetGene()->mID)
	//	{
	//		mAgents->erase(mAgents->begin() + index);
	//		mChromosome.erase(mChromosome.begin() + i);
	//	}
	//}
	//XMLHandler::StoreGenes("Chromosome.xml", mChromosome);
	XMLHandler::SaveFitness(mAgents->at(index)->GetChromosome()->GetGene());
	mAgents->erase(mAgents->begin() + index);
}

AgentManager::AgentManager()
{
}

AgentManager::~AgentManager()
{
}
