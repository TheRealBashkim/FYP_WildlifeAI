#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "Layer.h"
#include <vector>
#include "Structures.h"
class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();
	void Input(std::vector<float> Inputs);
	AgentNetworkOptions * Output();

private:
	Layer * mLayer;
};
#endif


