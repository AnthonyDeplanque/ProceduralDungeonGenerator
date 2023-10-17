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
	
	//inline ~Room() { std::cout << "room deleted" << std::endl; }
	
	inline Vector2d getCoords() { return coords; }
	inline int getAge() { return age; }


private:
	Vector2d coords;
	int age{};
};

