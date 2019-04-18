#include "Layer.h"



Layer::Layer()
{
}


Layer::~Layer()
{
}

void Layer::SetPerceptronAmount(int ammount)
{
	for (size_t i = 0; i < ammount; ++i)
	{
		Perceptron * _Perceptron = new Perceptron();

		mPerceptronAmmount->push_back(_Perceptron);
	}
}
