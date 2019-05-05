#ifndef NEURON
#define NEURON
#include <vector>
class Neuron
{
public:
	Neuron();
	~Neuron();
	void Input(std::vector<float> input);
	float Output();
	void SetWeight(float value) { _Weight = value; }
	float GetWeight() { return _Weight; }
	void SetBias(float bias) { _Bias = bias; }
	float GetBias() { return _Bias; }
	float AdjustWeight(float value);
private:
	float _Value;
	float _Weight = 0;
	float _Bias = 0;

};
#endif

