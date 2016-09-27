#pragma once
#include "IActivationFunction.h"
class BipolarSigmoidFunction :
	public IActivationFunction
{
public:
	BipolarSigmoidFunction();
	BipolarSigmoidFunction(double alpha);

	virtual double Function(double x);
	virtual double Derivative(double x);
	virtual double Derivative2(double x);
private:
	double alpha;
};

