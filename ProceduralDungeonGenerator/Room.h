#pragma once
#include <iostream>
#include "Direction.h"
#include "Neighbors.h"
class Room
{
public:
	inline Room(const int x, const int y) 
	{
		coords = Vector2d(0,0);
		neighbors = Neighbors();
		coords.setX(x);
		coords.setY(y);
		age = 0;
	};

	Room(Direction to, Room *parentRoomPtr) ;

	inline Vector2d getCoords() { return coords; }
	inline Neighbors *getNeighbors() { return &neighbors; }

private:
	Vector2d coords;
	Neighbors neighbors;
	int age{};
};

