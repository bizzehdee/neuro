#pragma once

class Layer;

class Network
{
public:
	Network(int inputsCount, int layersCount);
	~Network();

	virtual double *Compute(double *input);
	virtual void Randomize();

protected:
	int inputCount;
	int layerCount;
	Layer **layers;
	double *output;
};

