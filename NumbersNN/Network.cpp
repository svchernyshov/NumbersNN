#include "Network.h"

Network::Network() : neurons_(10)
{
	eps_ = 0.5;
	neurons_[0].setOm0(5);
	neurons_[1].setOm0(11);
	neurons_[2].setOm0(11);
	neurons_[3].setOm0(9);
	neurons_[4].setOm0(11);
	neurons_[5].setOm0(12);
	neurons_[6].setOm0(7);
	neurons_[7].setOm0(13);
	neurons_[8].setOm0(12);
	neurons_[9].setOm0(12);
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
	if (inputs.size() != 15 || outputs.size() != 10) {
		return false;
	}
	std::vector<int> realResult = run(inputs);
	if (realResult == outputs) {
		return false;
	}

	auto iter = realResult.begin();
	auto end = realResult.end();
	auto iterOutputs = outputs.begin();
	auto iterN = neurons_.begin();
	for (; iter != end; ++iter) {
		if (*iter != *iterOutputs) {
			iterN->educate(inputs, eps_*(*iterOutputs - *iter));
		}
		++iterOutputs;
		++iterN;
	}
	return true;
}