#pragma once
#include <iostream>
#include "Direction.h"
#include "Vector2d.h"
#include "DirectionIncrementation.h"
class Room
{
public:
	inline Room(const int x, const int y, int age) 
	{
		coords = Vector2d(0,0);
		coords.setX(x);
		coords.setY(y);
		age = age;
	};

	inline Room(Vector2d p_coords, int age) { 
		coords = p_coords; 
		age = age;
	}

	Room(Direction to, Room *parentRoomPtr, int age) ;
	
	//inline ~Room() { std::cout << "room deleted" << std::endl; }
	
	inline Vector2d getCoords() { return coords; }
	inline int getAge() { return age; }


private:
	Vector2d coords;
	int age{};
};

