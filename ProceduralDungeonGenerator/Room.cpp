#include "Room.h"
#include "DirectionIncrementation.h"

DirectionIncrementation d;


Room::Room(Direction to, Room* parentRoomPtr, int p_age) 
{
	std::cout << "Room ctor > " << parentRoomPtr << std::endl;
	coords = Vector2d(0, 0);
	coords += parentRoomPtr->getCoords();

	age = age;

	switch (to)
	{
	case Direction::NORTH:
		coords += d.NORTH_DIRECTION_INCREMENT;
		break;

	case Direction::SOUTH:
		coords += d.SOUTH_DIRECTION_INCREMENT;
		break;

	case Direction::EAST:
		coords += d.EAST_DIRECTION_INCREMENT;
		break;

	case Direction::WEST:
		coords += d.WEST_DIRECTION_INCREMENT;
		break;
	}
}




