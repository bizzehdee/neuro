#pragma once
class IUnsupervisedLearning {
	virtual double Run(double *input) = 0;
	virtual double RunEpoch(double **input) = 0;
};
