#include "Chromosome.h"



Chromosome::Chromosome()
{
}


Chromosome::~Chromosome()
{
}

void Chromosome::GenerateGene()
{
	float RandMaxAge = rand() % 130;
	mGene->maxAge = RandMaxAge;
	float RandStamina = rand() % 1000;
	mGene->maxStamina = RandStamina;
	float RandHealth = rand() % 120 + 50;
	mGene->health = RandHealth;
	float RandMaxSpeed = rand() % 300 + 100;
	mGene->maxSpeed = RandMaxSpeed;
}
