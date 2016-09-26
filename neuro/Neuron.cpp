#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron(int inputCount)
{
	this->inputCount = inputCount;
	this->weights = new double[this->inputCount];

	double a = Rand(), b = Rand();

	this->randRange = new DoubleRange(0, 1);
	this->Randomize();
}


Neuron::~Neuron()
{
	delete[] this->weights;
}

void Neuron::Randomize() 
{
	double d = randRange->Length();

	for (int i = 0; i < this->inputCount; i++) 
	{
		this->weights[i] = Rand() * d * randRange->Min();
	}
}
