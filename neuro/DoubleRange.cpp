#include "stdafx.h"
#include "DoubleRange.h"

DoubleRange::DoubleRange(double min, double max)
{
	this->min = min;
	this->max = max;
}

bool DoubleRange::IsInside(double x)
{
	return ((x >= this->min) && (x <= this->max));
}

bool DoubleRange::IsInside(DoubleRange *range) 
{
	return IsInside(range->Min()) && IsInside(range->Max());
}

bool DoubleRange::IsOverlapping(DoubleRange *range)
{
	return IsInside(range->Min()) || IsInside(range->Max());
}
