#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork()
{

}

NeuralNetwork::~NeuralNetwork()
{
}

void NeuralNetwork::Input(std::vector<float> Inputs)
{
	mLayer->Input(Inputs);
}

std::vector<float> NeuralNetwork::Output()
{
	return std::vector<float>();
}


