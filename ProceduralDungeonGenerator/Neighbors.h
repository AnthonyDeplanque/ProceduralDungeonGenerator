#pragma once
#include "Direction.h"

struct Neighbors
{
	Neighbors();
	Neighbors(Direction origin);
	bool northNeighbor{ false };
	bool southNeighbor{ false };
	bool eastNeighbor{ false };
	bool westNeighbor{ false };
	void setNeighBor(Direction to);
};


