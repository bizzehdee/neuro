#pragma once
#include "Network.h"

class DistanceNetwork :
	public Network
{
public:
	DistanceNetwork(int inputsCount, int neuronsCount);
	~DistanceNetwork();

	int GetWinner();
};

