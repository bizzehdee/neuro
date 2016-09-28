#include "stdafx.h"
#include "DistanceNeuron.h"

double neuro::DistanceNeuron::Compute(double *input)
{
	output = 0;

	for (int i = 0; i < this->inputCount; i++) 
	{
		output += abs(this->weights[i] - input[i]);
	}

	return output;
}
