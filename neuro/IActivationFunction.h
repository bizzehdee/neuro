#pragma once

class IActivationFunction {
public:
	virtual double Function(double x) = 0;
	virtual double Derivative(double x) = 0;
	virtual double Derivative2(double x) = 0;
};