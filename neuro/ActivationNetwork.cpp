#include "stdafx.h"
#include "ActivationNetwork.h"
#include "IActivationFunction.h"
#include "ActivationLayer.h"

neuro::ActivationNetwork::ActivationNetwork(IActivationFunction *function, int inputsCount, int *neuronCounts) :
	Network(inputsCount, sizeof(neuronCounts) / sizeof(int))
{
	for (int i = 0; i < this->layerCount; i++)
	{
		layers[i] = new ActivationLayer(neuronCounts[i], (i == 0) ? inputsCount : neuronCounts[i - 1], function);
	}
}

neuro::ActivationNetwork::~ActivationNetwork()
{
	for (int i = 0; i < this->layerCount; i++)
	{
		delete layers[i];
	}
}
