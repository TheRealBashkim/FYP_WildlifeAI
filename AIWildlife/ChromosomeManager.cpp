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
		temp->LoadTexture("Characters/Character.bmp");
		temp->SetPosition(m1->GetPosition());
		Chromosome * tempChromo = new Chromosome();
		tempChromo->SetGene(Crossover(m1->GetChromosome()->GetGene(), m2->GetChromosome()->GetGene()));
		tempChromo->GetGene()->mID = rand() % MaxInt;
		temp->SetChromosome(tempChromo);
		temp->SetStats();
		mAgent = (BaseAgent*)temp;
		//XMLHandler::AddGene("Chromosome.xml", tempChromo->GetGene());
		return mAgent;
	}
		CarnivoreAgent * temp = new CarnivoreAgent(m1->GetName(), m1->GetRenderer());
		temp->LoadTexture("Characters/Herbivore.bmp");
		temp->SetPosition(m1->GetPosition());
		Chromosome * tempChromo = new Chromosome();
		tempChromo->SetGene(Crossover(m1->GetChromosome()->GetGene(), m2->GetChromosome()->GetGene()));
		tempChromo->GetGene()->mID = rand() % MaxInt;
		temp->SetChromosome(tempChromo);
		temp->SetStats();
		mAgent = (BaseAgent*)temp;
		//XMLHandler::AddGene("Chromosome.xml", tempChromo->GetGene());
		return mAgent;
}

Gene * ChromosomeManager::GenerateGene()
{
	
	Gene * mGene = new Gene();
	int RandMaxAge = rand() % 100;
	mGene->maxAge = RandMaxAge;
	float RandStamina = rand() % 250;
	mGene->maxStamina = RandStamina;
	float RandHealth = rand() % 120 + 50;
	mGene->health = RandHealth;
	float RandMaxSpeed = rand() % 100 + 25;
	mGene->maxSpeed = RandMaxSpeed;
	int GenderRand = rand() % 100;
	if (GenderRand >= 50)
	{
		mGene->mGender = "Male";
	}
	else
	{
		mGene->mGender = "Female";
	}
	return mGene;
}

float ChromosomeManager::GenerateFitnessOfChromosome(Gene * gene)
{
	float maxValue = 0;
	maxValue += (gene->health / 170);
	maxValue += (gene->maxSpeed / 125);
	maxValue += (gene->maxStamina / 250);
	//maxValue += gene->mCurrentAge;
	maxValue += (gene->maxAge / 100);
	maxValue /= 100;
	return maxValue;
}

Gene* ChromosomeManager::Crossover(Gene* parent1, Gene* parent2)
{
	Gene * temp = new Gene();
	temp->mName = parent1->mName;
	/**
	Health*/
	int randHealth = rand() % 100;
	if (randHealth >= 50)
	{
		temp->health = parent2->health;
	}
	else
	{
		temp->health = parent1->health;
	}
	/**
	Age*/
	int randAge = rand() % 100;
	if (randAge >= 50)
	{
		temp->maxAge = parent2->maxAge;
	}
	else
	{
		temp->maxAge = parent1->maxAge;
	}
	/**
	Stamina*/
	int randStamina = rand() % 100;
	if (randStamina >= 50)
	{
		temp->maxStamina = parent2->maxStamina;
	}
	else
	{
		temp->maxStamina = parent1->maxStamina;
	}
	/**
	Speed*/
	int randSpeed = rand() % 100;
	if (randSpeed >= 50)
	{
		temp->maxSpeed = parent2->maxSpeed;
	}
	else
	{
		temp->maxSpeed = parent1->maxSpeed;
	}
	/**Gender
	*/
	int randGender = rand() % 100;
	if (randGender >= 50)
	{
		temp->mGender = parent2->mGender;
	}
	else
	{
		temp->mGender = parent1->mGender;
	}

	return Mutation(temp);

	//return temp;
}

Gene * ChromosomeManager::Mutation(Gene * tempCrossoverGene)
{
	// need to look up the rate of mutation to back up the rate of mutation

	if (rand() % 100 > 85)
	{
		tempCrossoverGene->health = rand() % 100 + 50;
	}
	if (rand() % 100 > 85)
	{
		tempCrossoverGene->maxAge = rand() % 130;
	}
	if (rand() % 100 > 85)
	{
		tempCrossoverGene->maxSpeed = rand() % 100 + 25;
	}
	if (rand() % 100 > 85)
	{
		tempCrossoverGene->maxStamina = rand() % 250;
	}
	return tempCrossoverGene;
}
