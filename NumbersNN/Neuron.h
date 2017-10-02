#pragma once

#include <vector>

class Neuron
{
public:
	// Заполнение массива весов нулевыми значениями, омега0 будет равна 0.
	Neuron(double om0 = 0.0);

	void setOm0(double om0);
	double om0() const;

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