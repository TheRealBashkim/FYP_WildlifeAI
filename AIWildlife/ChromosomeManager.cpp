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
		CarnivoreAgent * temp = new CarnivoreAgent(m1->GetName(),m1->GetRenderer());
		temp->LoadTexture("Character/Character.bmp");
		float tempx, tempy;
		tempx = rand() % 875;
		tempy = rand() % 875;
		temp->SetPosition(Vector2D(tempx, tempy));
		Chromosome * tempChromo = new Chromosome();
		tempChromo->SetGene(Crossover(m1->GetChromosome()->GetGene(), m2->GetChromosome()->GetGene()));
		temp->SetChromosome(tempChromo);
		temp->SetStats();
		mAgent = (BaseAgent*)temp;
		return mAgent;
	}
		CarnivoreAgent * temp = new CarnivoreAgent(m1->GetName(), m1->GetRenderer());
		temp->LoadTexture("Character/Herbivore.bmp");
		float tempx, tempy;
		tempx = rand() % 875;
		tempy = rand() % 875;
		temp->SetPosition(Vector2D(tempx, tempy));
		Chromosome * tempChromo = new Chromosome();
		tempChromo->SetGene(Crossover(m1->GetChromosome()->GetGene(), m2->GetChromosome()->GetGene()));
		temp->SetChromosome(tempChromo);
		temp->SetStats();
		mAgent = (BaseAgent*)temp;
		return mAgent;
}

Gene* ChromosomeManager::Crossover(Gene* parent1, Gene* parent2)
{
	Gene * temp = new Gene();
	temp->mName = parent1->mName;
	int splitamount = rand() % 5 + 1;
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

	case 4:
		temp->health = parent1->health;
		temp->maxAge = parent2->maxAge;
		temp->maxSpeed = parent1->maxSpeed;
		temp->maxStamina = parent2->maxStamina;
	case 5:
		temp->health = parent2->health;
		temp->maxAge = parent1->maxAge;
		temp->maxSpeed = parent2->maxSpeed;
		temp->maxStamina = parent1->maxStamina;
	}
	return temp;
}
