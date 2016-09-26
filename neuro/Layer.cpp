#include "stdafx.h"
#include "Layer.h"
#include "Neuron.h"

Layer::Layer(int neuronCount, int inputCount)
{
	this->inputCount = MAX(1, inputCount);
	this->neuronCount = MAX(1, neuronCount);

	this->neurons = new Neuron*[this->neuronCount];
	this->output = new double[this->neuronCount];
}

Layer::~Layer()
{
	delete this->neurons;
	delete this->output;
}

Neuron *Layer::operator[](const int index)
{
	return this->neurons[index];
}

double *Layer::Compute(double *input)
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		output[x] = this->neurons[x]->Compute(input);
	}

	return output;
}

void Layer::Randomize()
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		this[x].Randomize();
	}
}
