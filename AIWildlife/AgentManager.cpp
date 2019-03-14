#include "AgentManager.h"


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

int AgentManager::CheckMousePolling(Vector2D mousepos)
{
	int id = 500;
	for (int i = 0; i < mAgents->size(); i++)
	{
		if (PointInBoxCollision(mousepos, mAgents->at(i)->GetPosition(), mAgents->at(i)->GetWidth(), mAgents->at(i)->GetHeight()))
		{
			id = i;
		}
	}
	return id;

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



void AgentManager::KillAgents(int index)
{
	mAgents->erase(mAgents->begin() + index);
}

AgentManager::AgentManager()
{
}

AgentManager::~AgentManager()
{
}
