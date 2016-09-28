#include "stdafx.h"
#include "SigmoidFunction.h"

neuro::SigmoidFunction::SigmoidFunction()
{
}

neuro::SigmoidFunction::SigmoidFunction(double alpha)
{
	this->alpha = alpha;
}

double neuro::SigmoidFunction::Function(double x)
{
	return (1 / (1 + exp(-alpha * x)));
}

double neuro::SigmoidFunction::Derivative(double x)
{
	double y = Function(x);

	return (alpha * y * (1 - y));
}

double neuro::SigmoidFunction::Derivative2(double x)
{
	return (alpha * x * (1 - x));
}
