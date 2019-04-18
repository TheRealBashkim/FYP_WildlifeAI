#ifndef LAYER_H
#define LAYER_H
#include "Perceptron.h"
#include <vector>

class Layer
{
public:
	Layer();
	~Layer();
	void SetPerceptronAmount(int ammount);


private:
	std::vector<Perceptron*> * mPerceptronAmmount = new std::vector<Perceptron*>();



};
#endif

