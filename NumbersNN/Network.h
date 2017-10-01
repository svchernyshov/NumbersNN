#pragma once

#include <vector>

class Neuron;

class Network
{
public:
	/*
	Метод запускает классификатор, на вход подаются 15 сигналов, описывающих цифру в пикселях 5 на 3.
	На выходе 10-ти мерный массив с выходными значениями сети.
	*/
	std::vector<int> run(const std::vector<int> &inputs);

private:
	std::vector<Neuron> neurons_;
};	// class Network