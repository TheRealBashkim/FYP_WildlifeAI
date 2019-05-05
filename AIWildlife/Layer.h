#ifndef LAYER_H
#define LAYER_H
#include "Neuron.h"
#include "Commons.h"
#include <vector>

class Layer
{
public:
	Layer();
	~Layer();
	void Input(std::vector<float> Input);
	std::vector<float> Output();
private:
	std::vector<Neuron*> mNeuron = std::vector<Neuron*>();


};
#endif

