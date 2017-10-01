#pragma once

#include <vector>

class Neuron
{
public:
	// Функция подающая на вход нейрона значения и возвращающая результат.
	int run(const std::vector<int> &inputs);

private:
	// 15-ти мерный массив весов.
	std::vector<int> weight_;
	// Омега нулевое.
	int om0_;
};	// class Neuron