#pragma once

#include <vector>

class Neuron
{
public:
	Neuron();

	void setOm0(double om0) { om0_ = om0; }

	// Функция подающая на вход нейрона значения и возвращающая результат.
	int run(const std::vector<int> &inputs);

	// eps идет вместе со знаком!
	void educate(const std::vector<int> &inputs, double eps);

private:
	// 15-ти мерный массив весов.
	std::vector<double> weight_;
	// Омега нулевое.
	double om0_;
};	// class Neuron