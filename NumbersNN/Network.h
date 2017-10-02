#pragma once

#include <vector>

#include "Neuron.h"

class Network
{
public:
	Network(const std::vector<int> om0s = std::vector<int>(10, 10), double eps = 0.5);

	void setOm0s(const std::vector<int> om0s);
	std::vector<int> om0s() const;

	void setEps(double eps);
	double eps() const;

	/*
	Метод запускает классификатор, на вход подаются 15 сигналов, описывающих цифру в пикселях 5 на 3.
	На выходе 10-ти мерный массив с выходными значениями сети.
	*/
	std::vector<int> run(const std::vector<int> &inputs);

	// Возвращаемый флаг, указывает, было ли переобучение.
	bool educate(const std::vector<int> &inputs, const std::vector<int> outputs);

private:
	std::vector<Neuron> neurons_;

	double eps_;
};	// class Network