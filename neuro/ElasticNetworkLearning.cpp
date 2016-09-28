#include "stdafx.h"
#include "ElasticNetworkLearning.h"
#include "DistanceNetwork.h"
#include "DistanceLayer.h"
#include "Neuron.h"


neuro::ElasticNetworkLearning::ElasticNetworkLearning(DistanceNetwork * network)
{
	this->network = network;

	int neurons = this->network->Layers(0)->NeuronCount();
	double deltaAlpha = M_PI * 2 / neurons;
	double alpha = deltaAlpha;

	distance = new double[neurons];
	distance[0] = 0.0;

	for (int i = 1; i < neurons; i++)
	{
		double dx = 0.5 * cos(alpha) - 0.5;
		double dy = 0.5 * sin(alpha);

		distance[i] = dx * dx + dy * dy;

		alpha += deltaAlpha;
	}
}

neuro::ElasticNetworkLearning::~ElasticNetworkLearning()
{
	delete distance;
}

double neuro::ElasticNetworkLearning::Run(double *input)
{
	double error = 0.0;

	// compute the network
	network->Compute(input);
	int winner = network->GetWinner();

	Layer *layer = network->Layers(0);

	for (int j = 0, m = layer->NeuronCount(); j < m; j++)
	{
		Neuron *neuron = layer->Neurons(j);

		double factor = exp(-distance[abs(j - winner)] / squaredRadius2);

		for (int i = 0, n = neuron->InputCount(); i < n; i++)
		{
			// calculate the error
			double weight = neuron->Weight(i);
			double e = (input[i] - weight) * factor;
			error += abs(e);
			// update weight
			weight += e * learningRate;
			neuron->Weight(i, weight);
		}
	}

	return error;
}

double neuro::ElasticNetworkLearning::RunEpoch(double **input)
{
	int inputArrayLength = sizeof(input) / sizeof(double *); //???
	double error = 0.0;

	// walk through all training samples
	for(int x=0; x<inputArrayLength; x++)
	{
		error += Run(input[x]);
	}

	// return summary error
	return error;
}

double neuro::ElasticNetworkLearning::LearningRate() const
{
	return this->learningRate;
}

void neuro::ElasticNetworkLearning::LearningRate(const double rate)
{
	this->learningRate = MAX(0.0, MIN(1.0, rate));
}

double neuro::ElasticNetworkLearning::LearningRadius() const
{
	return this->learningRadius;
}

void neuro::ElasticNetworkLearning::LearningRadius(const double rate)
{
	this->learningRadius = MAX(0.0, MIN(1.0, rate));
	this->squaredRadius2 = 2 * this->learningRadius * this->learningRadius;
}
