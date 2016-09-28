#pragma once

namespace neuro {
	class Neuron;

	class Layer
	{
	public:
		~Layer();

		inline int InputCount() const { return this->inputCount; }
		inline int NeuronCount() const { return this->neuronCount; }

		double *Output() const { return this->output; }

		neuro::Neuron *operator[] (const int index);
		neuro::Neuron *Neurons(const int index);

		virtual double* Compute(double* input);
		virtual void Randomize();

	protected:
		Layer(int neuronCount, int inputCount);

		int inputCount = 0;
		int neuronCount = 0;

		neuro::Neuron **neurons = 0;
		double *output = 0;
	};

}
