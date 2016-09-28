#pragma once

namespace neuro {
	class ISupervisedLearning {
		virtual double Run(double *input, double *output) = 0;
		virtual double RunEpoch(double **input, double **output) = 0;
	};
}
