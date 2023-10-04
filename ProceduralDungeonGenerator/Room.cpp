#include "Room.h"
#include "DirectionIncrementation.h"
#include "Neighbors.h"

Room::Room(Direction to, Room parentRoom) {
	coords = parentRoom.getCoords();
	parentRoom.getNeighbors().setNeighBor(to);
	switch (to)
	{
	case Direction::NORTH:
		coords += DirectionIncrementation::NORTH_DIRECTION_INCREMENT;
		
		neighbors.setNeighBor(Direction::SOUTH);
		break;
	case Direction::SOUTH:
		coords += DirectionIncrementation::SOUTH_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::NORTH);
		break;
	case Direction::EAST:
		coords += DirectionIncrementation::EAST_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::WEST);
		break;
	case Direction::WEST:
		coords += DirectionIncrementation::WEST_DIRECTION_INCREMENT;
		neighbors.setNeighBor(Direction::EAST);
		break;
	}
};



