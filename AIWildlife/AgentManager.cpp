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

void AgentManager::GenerateBaseAgents()
{
	for(int i = 0; i< 15;i++)
	{
		HerbivoreAgent * temp = new HerbivoreAgent("Herbivore", mRenderer);
		temp->LoadTexture("Characters/Herbivore.bmp");
		float tempx, tempy;
		tempx = rand() % 875;
		tempy = rand() % 875;
		temp->SetPosition(Vector2D(tempx, tempy));
		BaseAgent * newTemp = (BaseAgent*)temp;
		mAgents->push_back(newTemp);
	}
	for(int i = 0; i < 15;i++)
	{
		CarnivoreAgent * temp = new CarnivoreAgent("Carnivore", mRenderer);
		temp->LoadTexture("Characters/Character.bmp");
		float tempx, tempy;
		tempx = rand() % 875;
		tempy = rand() % 875;
		temp->SetPosition(Vector2D(tempx, tempy));
		BaseAgent * newTemp = (BaseAgent*)temp;
		mAgents->push_back(newTemp);
	}
}

void AgentManager::Update(float dt)
{
	
	for(int i = 0; i < mAgents->size();i++)
	{
		// kills agent relating to old age
		if(mAgents->at(i)->GetAge() > 99)
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
