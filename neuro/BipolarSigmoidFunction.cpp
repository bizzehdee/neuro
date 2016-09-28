#include "stdafx.h"
#include "BipolarSigmoidFunction.h"

neuro::BipolarSigmoidFunction::BipolarSigmoidFunction()
{
	this->alpha = 2.0;
}

neuro::BipolarSigmoidFunction::BipolarSigmoidFunction(double alpha)
{
	this->alpha = alpha;
}

double neuro::BipolarSigmoidFunction::Function(double x)
{
	return ((2 / (1 + exp(-alpha * x))) - 1);
}

double neuro::BipolarSigmoidFunction::Derivative(double x)
{
	double y = Function(x);
	return (alpha * (1 - y * y) / 2);
}

double neuro::BipolarSigmoidFunction::Derivative2(double x)
{
	return (alpha * (1 - x * x) / 2);
}
