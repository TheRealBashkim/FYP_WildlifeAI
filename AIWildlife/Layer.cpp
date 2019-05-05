#include "Layer.h"



Layer::Layer()
{
}


Layer::~Layer()
{
}

void Layer::Input(std::vector<float> Input)
{
	if (mNeuron.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			Neuron * mNew = new Neuron();
			mNew->Input(Input);
			mNew->SetWeight(RandomFloat(0.0f,1.0f));
			mNew->SetBias(RandomFloat(0.0f, 1.0f));
			mNeuron.push_back(mNew);
		}
	}
	else
	{
		for (int i = 0; i < mNeuron.size(); i++)
		{
			mNeuron[i]->Input(Input);
			mNeuron[i]->SetWeight(mNeuron[i]->AdjustWeight(mNeuron[i]->GetWeight()));
			mNeuron[i]->SetBias(mNeuron[i]->AdjustWeight(mNeuron[i]->GetBias()));
		}
	}
}

std::vector<float> Layer::Output()
{
	std::vector<float> mValues;
	for (int i = 0; i < 2; i++)
	{
		float value;
		for (int j = 0; j < mNeuron.size(); j++)
		{
			value += mNeuron[i]->Output * mNeuron[i]->GetBias();
		}
		mValues.push_back(value);
	}
	return mValues;
}
