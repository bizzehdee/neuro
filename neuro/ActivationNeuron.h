#pragma once

#include "Neuron.h"
#include "IActivationFunction.h"

class ActivationNeuron : public Neuron
{
public:
	ActivationNeuron(int inputCount, IActivationFunction *activationFunction);

	double Threshold() const { return this->threshold; }
	void Threshold(const double x) { this->threshold = x; }


	IActivationFunction *ActivationFunction() { return this->activationFunction; }

	virtual void Randomize();
	virtual double Compute(double *input);
protected:
	double threshold = 0;
	IActivationFunction *activationFunction = 0;

};

