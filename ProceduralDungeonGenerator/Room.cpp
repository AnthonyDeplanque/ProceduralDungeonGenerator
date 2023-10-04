#include "Room.h"
#include "DirectionIncrementation.h"
#include "Neighbors.h"

DirectionIncrementation d;


Room::Room(Direction to, Room* parentRoomPtr) 
{
	std::cout << "Room ctor > " << parentRoomPtr << std::endl;
	coords = Vector2d(0, 0);
	coords += parentRoomPtr->getCoords();
	parentRoomPtr->getNeighbors()->setNeighBor(to);

	switch (to)
	{
	case Direction::NORTH:
		coords += d.NORTH_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::SOUTH);
		break;

	case Direction::SOUTH:
		coords += d.SOUTH_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::NORTH);
		break;

	case Direction::EAST:
		coords += d.EAST_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::WEST);
		break;

	case Direction::WEST:
		coords += d.WEST_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::EAST);
		break;
	}

}



