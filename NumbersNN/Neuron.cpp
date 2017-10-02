#include "Neuron.h"

Neuron::Neuron(double om0) : weight_(15, 0)
{
	om0_ = om0;
}

void Neuron::setOm0(double om0)
{
	om0_ = om0;
}

double Neuron::om0() const
{
	return om0_;
}

int Neuron::run(const std::vector<int> &inputs)
{
	if (inputs.size() != 15) {
		return -1;
	}
	int sum = 0;
	auto iter = inputs.begin();
	auto end = inputs.end();
	auto iterW = weight_.begin();
	for (; iter != end; ++iter) {
		sum += (*iter)*(*iterW);
		++iterW;
	}
	sum -= om0_;
	if (sum > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void Neuron::educate(const std::vector<int> &inputs, double eps)
{
	if (inputs.size() != 15) {
		return;
	}
	auto iter = weight_.begin();
	auto end = weight_.end();
	auto iterI = inputs.begin();
	for (; iter != end; ++iter) {
		*iter = *iter + eps*(*iterI);
		++iterI;
	}
}