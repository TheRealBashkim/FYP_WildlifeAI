#include "PlantManager.h"



PlantManager::PlantManager(SDL_Renderer * Renderer)
{
	mRenderer = Renderer;
	for(int i = 0; i < 20;i++)
	{
		Plant tempPlant = Plant(mRenderer);
		tempPlant.LoadTexture("Tiles/FoodTile.bmp");
		tempPlant.GeneratePosition();
		tempPlant.SetStatIncrease(10.0f);
		mPlantList->push_back(tempPlant);
	}
}

PlantManager::~PlantManager()
{
}

void PlantManager::Update(std::vector<BaseAgent*>* agents,float dt)
{
	/**
	 * Checks for collision with agents and plants.
	 */
	
	
	for(int i = 0; i < mPlantList->size(); i++)
	{
		mPlantList->at(i).Update(dt);
		for(int j = 0; j <agents->size();j++)
		{
			if(BoxToBox(*mPlantList->at(i).GetPosition(),mPlantList->at(i).GetWidth(),mPlantList->at(i).GetHeight(),
				agents->at(j)->GetPosition(),agents->at(j)->GetWidth(),agents->at(j)->GetHeight()))
			{
				if(agents->at(j)->GetName() == "Herbivore" && agents->at(j)->GetChromosome()->GetGene()->mCurrentStamina < 30)
				{
					agents->at(j)->GetChromosome()->GetGene()->mCurrentStamina += mPlantList->at(i).GetStatIncrease();
					//mPlantList->erase(mPlantList->begin() + i);
					mPlantList->at(i).GeneratePosition();
					mPlantList->at(i).SetSpawned(false);
				}
			}
		}
	}
	//SpawnNewItem();
}

void PlantManager::Draw()
{
	for(int i = 0; i < mPlantList->size();i++)
	{
		mPlantList->at(i).Draw();
	}
}

void PlantManager::SpawnNewItem()
{
	
}
