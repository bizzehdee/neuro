#pragma once

#include "DoubleRange.h"

namespace neuro {
	class Neuron
	{
	public:
		~Neuron();

		virtual void Randomize();
		virtual double Compute(double *input) = 0; // pure virtual


		double Weight(int n) const { return this->weights[n]; }
		void Weight(int n, const double w) { this->weights[n] = w; }

		double Output() const { return this->output; }

		int InputCount() const { return this->inputCount; }

	protected:
		Neuron(int inputCount);

		int inputCount = 0;
		double *weights;
		double output = 0;

		DoubleRange *randRange;

		inline double Rand() { return (double)rand() / RAND_MAX; }
	};
}
