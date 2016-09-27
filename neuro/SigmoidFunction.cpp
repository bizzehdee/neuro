#include "stdafx.h"
#include "SigmoidFunction.h"

SigmoidFunction::SigmoidFunction()
{
}

SigmoidFunction::SigmoidFunction(double alpha)
{
	this->alpha = alpha;
}

double SigmoidFunction::Function(double x)
{
	return (1 / (1 + exp(-alpha * x)));
}

double SigmoidFunction::Derivative(double x)
{
	double y = Function(x);

	return (alpha * y * (1 - y));
}

double SigmoidFunction::Derivative2(double x)
{
	return (alpha * x * (1 - x));
}
