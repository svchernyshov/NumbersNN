#include "Network.h"
#include "Neuron.h"

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