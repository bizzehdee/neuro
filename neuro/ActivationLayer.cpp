#include "stdafx.h"
#include "ActivationLayer.h"
#include "ActivationNeuron.h"

neuro::ActivationLayer::ActivationLayer(int neuronCount, int inputCount, IActivationFunction *activationFunction) :
	Layer(neuronCount, inputCount)
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		this->neurons[x] = new ActivationNeuron(inputCount, activationFunction);
	}
}


neuro::ActivationLayer::~ActivationLayer()
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		delete this->neurons[x];
	}
}

neuro::ActivationNeuron * neuro::ActivationLayer::operator[](const int index)
{
	return (ActivationNeuron *)this->neurons[index];
}
