#include "Network.h"



Network::Network()
{
}


Network::~Network()
{
}

void Network::SetLayerAmmount(int LayerAmmount, int PerceptronAmount)
{
	for (size_t i = 0; i < LayerAmmount; ++i)
	{
		Layer * mTempLayer = new Layer();
		mTempLayer->SetPerceptronAmount(PerceptronAmount);
		/**
		Setup Layer Information
		*/
		mLayerVector->push_back(mTempLayer);
	}
}
