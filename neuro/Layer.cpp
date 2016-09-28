#include "stdafx.h"
#include "Layer.h"
#include "Neuron.h"

neuro::Layer::Layer(int neuronCount, int inputCount)
{
	this->inputCount = MAX(1, inputCount);
	this->neuronCount = MAX(1, neuronCount);

	this->neurons = new Neuron*[this->neuronCount];
	this->output = new double[this->neuronCount];
}

neuro::Layer::~Layer()
{
	delete this->neurons;
	delete this->output;
}

neuro::Neuron *neuro::Layer::operator[](const int index)
{
	return this->neurons[index];
}

double *neuro::Layer::Compute(double *input)
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		output[x] = this->neurons[x]->Compute(input);
	}

	return output;
}

void neuro::Layer::Randomize()
{
	for (int x = 0; x < this->neuronCount; x++)
	{
		this->neurons[x]->Randomize();
	}
}
