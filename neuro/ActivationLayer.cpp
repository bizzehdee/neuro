#include "stdafx.h"
#include "ActivationLayer.h"
#include "ActivationNeuron.h"

ActivationLayer::ActivationLayer(int neuronCount, int inputCount, IActivationFunction *activationFunction) :
	Layer(neuronCount, inputCount)
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		this->neurons[x] = new ActivationNeuron(inputCount, activationFunction);
	}
}


ActivationLayer::~ActivationLayer()
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		delete this->neurons[x];
	}
}

ActivationNeuron *ActivationLayer::operator[](const int index)
{
	return (ActivationNeuron *)this->neurons[index];
}
