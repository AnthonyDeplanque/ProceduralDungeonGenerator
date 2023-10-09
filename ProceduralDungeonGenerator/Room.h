#pragma once
#include <iostream>
#include "Direction.h"
#include "Vector2d.h"
class Room
{
public:
	inline Room(const int x, const int y) 
	{
		coords = Vector2d(0,0);
		coords.setX(x);
		coords.setY(y);
		age = 0;
	};

	inline Room(Vector2d p_coords) { 
		coords = p_coords; 
		age = 0;
	}

	Room(Direction to, Room *parentRoomPtr) ;
	inline Vector2d getCoords() { return coords; }


private:
	Vector2d coords;
	int age{};
};

