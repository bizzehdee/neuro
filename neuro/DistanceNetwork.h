#pragma once
#include "Network.h"

namespace neuro {
	class DistanceNetwork :
		public Network
	{
	public:
		DistanceNetwork(int inputsCount, int neuronsCount);
		~DistanceNetwork();

		int GetWinner();
	};
}
