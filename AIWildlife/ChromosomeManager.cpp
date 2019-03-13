#include "ChromosomeManager.h"



ChromosomeManager::ChromosomeManager()
{
}


ChromosomeManager::~ChromosomeManager()
{
}

void ChromosomeManager::GenerateChromosome()
{
	
		Gene _TempGene;
		
		float RandMaxAge = rand() % 130;
		_TempGene.maxAge = RandMaxAge;
		float RandStamina = rand() % 1000;
		_TempGene.maxStamina = RandStamina;
		float RandHealth = rand() % 120 + 50;
		_TempGene.health = RandHealth;
		float RandMaxSpeed = rand() % 300 + 100;
		_TempGene.maxSpeed = RandMaxSpeed;

		Chromosome * tempChromo = new Chromosome();
		tempChromo->SetGene(&_TempGene);
		mChromosomes.push_back(tempChromo);

	XMLHandler::StoreGenes("Chromosome.xml", mChromosomes);
}
