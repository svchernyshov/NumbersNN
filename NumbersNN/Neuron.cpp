#include "Neuron.h"

// У каждого нейрона 15 входов.
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
	const size_t numInputs = 15;
	if (inputs.size() != numInputs) {
		return -1;
	}
	double sum = 0.0;
	auto iter = inputs.begin();
	auto end = inputs.end();
	auto iterW = weight_.begin();
	for (; iter != end; ++iter) {
		sum += (*iter)*(*iterW);
		++iterW;
	}
	sum -= om0_;
	// > или >= ? Сильно меняется скорость обучения.
	if (sum > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void Neuron::educate(const std::vector<int> &inputs, double eps)
{
	const size_t numInputs = 15;
	if (inputs.size() != numInputs) {
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