#pragma once

#include "Neuron.h"

namespace neuro {
	class DistanceNeuron : public Neuron
	{
	public:
		DistanceNeuron(int inputCount) : Neuron(inputCount) {  }

		virtual double Compute(double *input);
	};
}
