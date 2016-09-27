#pragma once

class Layer;

class Network
{
public:
	Network(int inputsCount, int layersCount);
	~Network();

	virtual double *Compute(double *input);
	virtual void Randomize();

private:
	int inputCount;
	int layerCount;

protected:
	Layer **layers;
	double *output;
};

