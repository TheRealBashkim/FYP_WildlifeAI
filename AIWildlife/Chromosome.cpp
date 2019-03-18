#include "Chromosome.h"



Chromosome::Chromosome()
{
	mGene = new Gene();
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
	float RandMaxSpeed = rand() % 100 + 25;
	mGene->maxSpeed = RandMaxSpeed;
	int GenderRand = rand() % 100;
	if(GenderRand >= 50)
	{
		mGene->mGender = "Male";
	}
	else
	{
		mGene->mGender = "Female";
	}
	//switch (GenderRand)
	//{
	//case 0:
	//	mGene->mGender = "Male";
	//	break;
	//case 1:
	//	mGene->mGender = "Female";
	//	break;
	//}
}
