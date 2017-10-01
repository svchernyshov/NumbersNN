#pragma once

#include <vector>

#include "Neuron.h"

class Network
{
public:
	Network();
	/*
	Метод запускает классификатор, на вход подаются 15 сигналов, описывающих цифру в пикселях 5 на 3.
	На выходе 10-ти мерный массив с выходными значениями сети.
	*/
	std::vector<int> run(const std::vector<int> &inputs);

	// возвращаемый флаг, указывает, было ли переобучение.
	bool educate(const std::vector<int> &inputs, const std::vector<int> outputs);

private:
	std::vector<Neuron> neurons_;

	double eps_;
};	// class Network