#include "Neighbors.h"

Neighbors::Neighbors() = default;
Neighbors::Neighbors(Direction origin)
{
	switch (origin)
	{
	case Direction::NORTH:
		southNeighbor = true;
		break;
	case Direction::SOUTH:
		northNeighbor = true;
		break;
	case Direction::EAST:
		westNeighbor = true;
		break;
	case Direction::WEST:
		eastNeighbor = true;
		break;
	}
}

void Neighbors::setNeighBor(Direction to)
{
	switch (to)
	{
	case Direction::NORTH:
		northNeighbor = true;
		break;
	case Direction::SOUTH:
		southNeighbor = true;
		break;
	case Direction::EAST:
		eastNeighbor = true;
		break;
	case Direction::WEST:
		westNeighbor = true;
		break;
	}
}
