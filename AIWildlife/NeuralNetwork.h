#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "Layer.h"
#include <vector>
class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();
	void Input(std::vector<float> Inputs);
	std::vector<float> Output();

private:
	Layer * mLayer;
};
#endif


