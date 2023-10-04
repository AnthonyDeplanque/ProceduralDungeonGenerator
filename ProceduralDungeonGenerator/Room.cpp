#include "Room.h"
#include "DirectionIncrementation.h"
#include "Neighbors.h"

DirectionIncrementation d;

Room::Room(Direction to, Room &parentRoom) {
	coords = Vector2d(0, 0);
	coords += parentRoom.getCoords();
	parentRoom.getNeighbors().setNeighBor(to);
	
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
};



