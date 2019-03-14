#include "ChromosomeManager.h"
#include "CarnivoreAgent.h"


ChromosomeManager::ChromosomeManager()
{
}


ChromosomeManager::~ChromosomeManager()
{
}

BaseAgent* ChromosomeManager::GenerateNewAgent(BaseAgent* m1, BaseAgent* m2)
{
	BaseAgent * mAgent;
	if(m1->GetName() == "Carnivore")
	{
		CarnivoreAgent * tempA = new CarnivoreAgent(m1->GetName(),m1->GetRenderer());
		tempA->LoadTexture("Character/Character.bmp");
		

	}
	else if(m1->GetName() == "Herbivore")
	{
		


	}


}

Gene* ChromosomeManager::Crossover(Gene* parent1, Gene* parent2)
{
	Gene * temp = new Gene();
	temp->mName = parent1->mName;
	int splitamount = rand() % 3 + 1;
	switch (splitamount)
	{
	case 1:
		temp->health = parent1->health;
		temp->maxAge = parent1->maxAge;
		temp->maxSpeed = parent1->maxSpeed;
		temp->maxStamina = parent2->maxStamina;
		break;
	case 2:
		temp->health = parent1->health;
		temp->maxAge = parent1->maxAge;
		temp->maxSpeed = parent2->maxSpeed;
		temp->maxStamina = parent2->maxStamina;
		break;

	case 3:
		temp->health = parent1->health;
		temp->maxAge = parent2->maxAge;
		temp->maxSpeed = parent2->maxSpeed;
		temp->maxStamina = parent2->maxStamina;
		break;
	}
	return temp;
}
