#ifndef NETWORK_H
#define NETWORK_H
#include "Layer.h"
#include <vector>
class Network
{
public:
	Network();
	~Network();
	void SetLayerAmmount(int mLayerAmmount,int InputOutputAmmount );
private:
	std::vector<Layer*> * mLayerVector = new std::vector<Layer*>();

};
#endif


