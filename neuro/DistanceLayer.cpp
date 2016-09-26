#include "stdafx.h"
#include "DistanceLayer.h"
#include "DistanceNeuron.h"

DistanceLayer::DistanceLayer(int neuronCount, int inputCount) : 
	Layer(neuronCount, inputCount)
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		this->neurons[x] = new DistanceNeuron(inputCount);
	}
}


DistanceLayer::~DistanceLayer()
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		delete this->neurons[x];
	}
}

DistanceNeuron *DistanceLayer::operator[](const int index)
{
	return (DistanceNeuron *)this->neurons[index];
}
