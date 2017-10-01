#include "Neuron.h"

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
	if (sum >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}