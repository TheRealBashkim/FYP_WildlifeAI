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
		if(mAgents->at(i)->GetAge() >= mAgents->at(i)->GetMaxAge() || mAgents->at(i)->GetStamina() <= 0)
		{
			KillAgents(i);
		}
		else
		{
			mAgents->at(i)->Update(dt);
			CheckForChildGenerationCollision(mAgents->at(i));
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
				//cout << "Heading x = " << heading.x << " y = " << heading.y << endl;
				double dotProduct = heading.Dot(vectotarget);
				//cout << "dot = " << dotProduct << endl;
				if (dotProduct > 0.85)
				{
					
					//Tank is within fov, but is there a building in the way?
					VisibleAgents.push_back(mAgents->at(i));
				}
			}
		}
	}

return VisibleAgents;
}

void AgentManager::CheckForChildGenerationCollision(BaseAgent * mAgent)
{
	std::vector<BaseAgent*> visibleAgents = mAgent->GetAgentsICanSee();
	for (int i = 0; i < visibleAgents.size(); i++)
	{
		if (BoxToBox(mAgent->GetPosition(), mAgent->GetWidth(), mAgent->GetHeight(), visibleAgents.at(i)->GetPosition(), visibleAgents.at(i)->GetWidth(), visibleAgents.at(i)->GetHeight()))
		{
			if (visibleAgents.at(i)->GetName() == mAgent->GetName())
			{
				if (mAgent->GetChromosome()->GetGene()->mGender == "Male" && visibleAgents.at(i)->GetChromosome()->GetGene()->mGender == "Female"
					|| mAgent->GetChromosome()->GetGene()->mGender == "Female" && visibleAgents.at(i)->GetChromosome()->GetGene()->mGender == "Male")
				{
					if (mAgent->GetChromosome()->GetGene()->mGender == "Female" || visibleAgents.at(i)->GetChromosome()->GetGene()->mGender == "Female")
					{
							BaseAgent * TempAgent = ChromosomeManager::GenerateNewAgent(mAgent,visibleAgents.at(i));
							mAgents->push_back(TempAgent);
					}
				}
			}

		}
	}
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
	mAgents->erase(mAgents->begin() + index);
}

AgentManager::AgentManager()
{
}

AgentManager::~AgentManager()
{
}
