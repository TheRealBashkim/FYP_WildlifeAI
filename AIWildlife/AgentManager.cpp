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
	
	for(int i = 0; i < mAgents->size();i++)
	{
		// kills agent relating to old age
		if(mAgents->at(i)->GetAge() >= mAgents->at(i)->GetMaxAge())
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

void AgentManager::CheckForChildGenerationCollision()
{
	for(int i = 0; i < mAgents->size();i++)
	{
		for(int j = 0; mAgents->size();i++)
		{
			if (mAgents->at(i)->GetChromosome()->GetGene()->mID == mAgents->at(j)->GetChromosome()->GetGene()->mID)
			{
				continue;
			}
			if(BoxToBox(mAgents->at(i)->GetPosition(), mAgents->at(i)->GetWidth(), mAgents->at(i)->GetHeight(),mAgents->at(j)->GetPosition(), mAgents->at(j)->GetWidth(), mAgents->at(i)->GetHeight()))
			{
				if(mAgents->at(i)->GetName() == mAgents->at(j)->GetName())
				{
					if(mAgents->at(i)->GetChromosome()->GetGene()->mGender == "Male" && mAgents->at(j)->GetChromosome()->GetGene()->mGender == "Female"
					|| mAgents->at(i)->GetChromosome()->GetGene()->mGender == "Female" && mAgents->at(j)->GetChromosome()->GetGene()->mGender == "Male")
					{
						
					}
				}

			}
		}
	}


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
