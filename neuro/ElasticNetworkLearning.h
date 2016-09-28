#pragma once
#include "IUnsupervisedLearning.h"

namespace neuro {
	class DistanceNetwork;

	class ElasticNetworkLearning :
		public IUnsupervisedLearning
	{
	public:
		ElasticNetworkLearning(DistanceNetwork *network);
		~ElasticNetworkLearning();

		virtual double Run(double *input) ;
		virtual double RunEpoch(double **input);

		double LearningRate() const;
		void LearningRate(const double rate);
		double LearningRadius() const;
		void LearningRadius(const double rate);

	private:
		DistanceNetwork *network;
		// array of distances between neurons
		double *distance;
		// learning rate
		double learningRate = 0.1;
		// learning radius
		double learningRadius = 0.5;
		// squared learning radius multiplied by 2 (precalculated value to speed up computations)
		double squaredRadius2 = 2 * 7 * 7;
	};
}
