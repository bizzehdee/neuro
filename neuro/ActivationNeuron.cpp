#include "stdafx.h"

#include "ActivationNeuron.h"

ActivationNeuron::ActivationNeuron(int inputCount, IActivationFunction *activationFunction) : Neuron(inputCount)
{
	this->activationFunction = activationFunction;
}

void ActivationNeuron::Randomize()
{
	Neuron::Randomize();

	threshold = Rand() * randRange->Length() + randRange->Min();
}

double ActivationNeuron::Compute(double *input) 
{
	double sum = 0;

	for (int i = 0; i < this->inputCount; i++) 
	{
		sum += this->weights[i] * input[i];
	}

	sum += threshold;

	output = activationFunction->Function(sum);

	return output;
}
