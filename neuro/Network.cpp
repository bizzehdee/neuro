#include "stdafx.h"
#include "Network.h"
#include "Layer.h"

neuro::Network::Network(int inputsCount, int layersCount)
{
	this->inputCount = MAX(1, inputsCount);
	this->layerCount = MAX(1, layersCount);

	this->layers = new Layer*[this->layerCount];
}


neuro::Network::~Network()
{
	delete this->layers;
}

double *neuro::Network::Compute(double *input)
{
	output = input;
	
	for (int x = 0; x < this->layerCount; x++) {
		output = this->layers[x]->Compute(output);
	}

	return output;
}

void neuro::Network::Randomize()
{
	for (int x = 0; x < this->layerCount; x++) {
		this->layers[x]->Randomize();
	}
}
