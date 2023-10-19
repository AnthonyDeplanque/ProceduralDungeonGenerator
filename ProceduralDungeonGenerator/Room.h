#pragma once
#include <iostream>
#include "Direction.h"
#include "Vector2d.h"
class Room
{
public:
	inline Room(const int x, const int y, int p_age) 
	{
		coords = Vector2d(0,0);
		coords.setX(x);
		coords.setY(y);
		age = p_age;
	};

	inline Room(Vector2d p_coords, int p_age) { 
		coords = p_coords; 
		age = p_age;
	}

	Room(Direction to, Room *parentRoomPtr, int p_age) ;
	
	//inline ~Room() { std::cout << "room deleted" << std::endl; }
	
	inline Vector2d getCoords() { return coords; }
	inline int getAge() { return age; }


private:
	Vector2d coords;
	int age{};
};

