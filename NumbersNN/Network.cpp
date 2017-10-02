#include "Network.h"

Network::Network(const std::vector<int> om0s, double eps) : neurons_(10)
{
	if (eps > 0 && eps < 1)
		eps_ = eps;
	else
		eps_ = 0.5;
	const size_t numNeurons = 10;
	for (size_t i = 0; i < numNeurons; ++i) {
		neurons_[i].setOm0(om0s[i]);
	}
}

void Network::setEps(double eps)
{
	if (eps > 0 && eps < 1)
		eps_ = eps;
}

double Network::eps() const
{
	return eps_;
}

void Network::setOm0s(const std::vector<int> om0s)
{
	const size_t numNeurons = 10;
	if (om0s.size() == numNeurons) {
		for (size_t i = 0; i < numNeurons; ++i) {
			neurons_[i].setOm0(om0s[i]);
		}
	}
}

std::vector<double> Network::om0s() const
{
	std::vector<double> result;
	const size_t numNeurons = 10;
	for (size_t i = 0; i < numNeurons; ++i) {
		result.push_back(neurons_[i].om0());
	}
	return result;
}

std::vector<int> Network::run(const std::vector<int> &inputs)
{
	std::vector<int> result;
	auto iter = neurons_.begin();
	auto end = neurons_.end();
	for (; iter != end; ++iter) {
		result.push_back(iter->run(inputs));
	}
	return result;
}

bool Network::educate(const std::vector<int> &inputs, const std::vector<int> outputs)
{
	const size_t numNeurons = 10;
	const size_t numInputs = 15;
	if (inputs.size() != numInputs || outputs.size() != numNeurons) {
		return false;
	}
	std::vector<int> realResult = run(inputs);
	if (realResult == outputs) {
		return false;
	}

	auto iterRealRes = realResult.begin();
	auto end = realResult.end();
	auto iterOutputs = outputs.begin();
	auto iterN = neurons_.begin();
	for (; iterRealRes != end; ++iterRealRes) {
		if (*iterRealRes != *iterOutputs) {
			iterN->educate(inputs, eps_*(*iterOutputs - *iterRealRes));
		}
		++iterOutputs;
		++iterN;
	}
	return true;
}