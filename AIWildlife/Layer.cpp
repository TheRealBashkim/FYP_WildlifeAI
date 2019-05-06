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
			mNew->SetWeight(RandomFloat(0.0f,1.0f));
			mNew->SetBias(RandomFloat(0.0f, 1.0f));
			mNew->Input(Input);
			mNeuron->push_back(mNew);
		}
	}
	else
	{
		for (int i = 0; i < mNeuron->size(); i++)
		{
			mNeuron->at(i)->Input(Input);
			mNeuron->at(i)->SetWeight(mNeuron->at(i)->AdjustWeight(mNeuron->at(i)->GetWeight()));
			mNeuron->at(i)->SetBias(mNeuron->at(i)->AdjustWeight(mNeuron->at(i)->GetBias()));
		}
	}
}

std::vector<float> Layer::Output()
{
	std::vector<float> mValues;
	for (int i = 0; i < 4; i++)
	{
		float value;
		for (int j = 0; j < mNeuron->size(); j++)
		{
			value += mNeuron->at(i)->Output() * mNeuron->at(i)->GetBias();
		}
		mValues.push_back(value);
	}
	return mValues;
}
