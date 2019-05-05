#include "Neuron.h"



Neuron::Neuron()
{
}

Neuron::~Neuron()
{

}

void Neuron::Input(std::vector<float> input)
{
	float net = 0;
	for (int i = 0; i < input.size(); i++)
	{
		net += input.at(i) * _Weight;
	}
	_Value = 1 / (1 + exp(-net));
}

float Neuron::Output()
{
	return _Value;
}

float Neuron::AdjustWeight(float value)
{
	//Mutation 
	int mutationchance = rand() % 100;
	if (mutationchance >= 50)
	{
		int incrementchance = rand() % 100;
		if (incrementchance >= 50)
		{
			value += 0.1f;
		}
		else
		{
			value -= 0.1f;
		}
	}
	return value;
}
