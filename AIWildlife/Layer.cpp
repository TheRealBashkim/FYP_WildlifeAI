#include "Layer.h"



Layer::Layer()
{
	mNeuron = new std::vector<Neuron*>();
}


Layer::~Layer()
{
}

void Layer::Input(std::vector<float> Input)
{
	if (mNeuron->empty())
	{
		for (int i = 0; i < 8; i++)
		{
			Neuron * mNew = new Neuron();
			mNew->SetWeight(RandomFloat(-1.0f,1.0f));
			mNew->SetBias(RandomFloat(-1.0f, 1.0f));
			mNew->ClearValue();
			mNew->Input(Input);
			mNeuron->push_back(mNew);
		}
	}
	else
	{
		for (int i = 0; i < mNeuron->size(); i++)
		{
			mNeuron->at(i)->SetWeight(mNeuron->at(i)->AdjustWeight(mNeuron->at(i)->GetWeight()));
			mNeuron->at(i)->SetBias(mNeuron->at(i)->AdjustWeight(mNeuron->at(i)->GetBias()));
			mNeuron->at(i)->ClearValue();
			mNeuron->at(i)->Input(Input);
		}
	}
}

std::vector<float> Layer::Output()
{
	std::vector<float> mValues;
	float value = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < mNeuron->size(); j++)
		{
			value += mNeuron->at(i)->Output();
		}
		//float sig = 1 / (1 + exp(-value));
		mValues.push_back(value);
		value = 0;
	}
	return mValues;
}
