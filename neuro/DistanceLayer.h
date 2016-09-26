#pragma once
#include "Layer.h"

class DistanceNeuron;

class DistanceLayer :
	public Layer
{
public:
	DistanceLayer(int neuronCount, int inputCount);
	~DistanceLayer();

	DistanceNeuron *operator[] (const int index);
};

