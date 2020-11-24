#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork()
{
	mLayer = new Layer();
}

NeuralNetwork::~NeuralNetwork()
{
}

void NeuralNetwork::Input(std::vector<float> Inputs)
{
	mLayer->Input(Inputs);
}

AgentNetworkOptions * NeuralNetwork::Output()
{
	std::vector<AgentNetworkOptions*> mOptions;
	std::vector<float> mValues = mLayer->Output();
	for (int i = 0; i < mValues.size(); i++)
	{
		AgentNetworkOptions * Outputs = new AgentNetworkOptions();
		Outputs->Option = GetValue(i);
		Outputs->val = mValues.at(i);
		mOptions.push_back(Outputs);
	}
	AgentNetworkOptions * best = mOptions.at(0);
	for (int i = 1; i < mOptions.size(); i++)
	{
		if (mOptions.at(i)->val > best->val)
		{
			best = mOptions.at(i);
		}
	}
	return best;
}


