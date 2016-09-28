#include "stdafx.h"
#include "ThresholdFunction.h"

double neuro::ThresholdFunction::Function(double x)
{
	return (x >= 0) ? 1 : 0;
}

double neuro::ThresholdFunction::Derivative(double x)
{
	return 0.0;
}

double neuro::ThresholdFunction::Derivative2(double x)
{
	return 0.0;
}
