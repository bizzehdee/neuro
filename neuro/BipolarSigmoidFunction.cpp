#include "stdafx.h"
#include "BipolarSigmoidFunction.h"

BipolarSigmoidFunction::BipolarSigmoidFunction()
{
	this->alpha = 2.0;
}

BipolarSigmoidFunction::BipolarSigmoidFunction(double alpha)
{
	this->alpha = alpha;
}

double BipolarSigmoidFunction::Function(double x)
{
	return ((2 / (1 + exp(-alpha * x))) - 1);
}

double BipolarSigmoidFunction::Derivative(double x)
{
	double y = Function(x);
	return (alpha * (1 - y * y) / 2);
}

double BipolarSigmoidFunction::Derivative2(double x)
{
	return (alpha * (1 - x * x) / 2);
}
