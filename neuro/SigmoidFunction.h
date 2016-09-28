#pragma once
#include "IActivationFunction.h"

namespace neuro {
	class SigmoidFunction :
		public IActivationFunction
	{
	public:
		SigmoidFunction();
		SigmoidFunction(double alpha);

		virtual double Function(double x);
		virtual double Derivative(double x);
		virtual double Derivative2(double x);

	private:
		double alpha = 2.0;
	};
}
