#pragma once
#include <iostream>
#include "Direction.h"
#include "Neighbors.h"
class Room
{
public:
	inline Room(int x, int y) {
		coords.setX(x);
		coords.setY(y);
	};
	Room(Direction to, Room parentRoom) ;

	inline Vector2d getCoords() { return coords; }
	inline Neighbors getNeighbors() { return neighbors; }

private:
	Vector2d coords{};
	Neighbors neighbors{};
};

