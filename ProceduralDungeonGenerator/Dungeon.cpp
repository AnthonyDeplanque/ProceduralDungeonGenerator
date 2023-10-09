#include "Dungeon.h"
#include "Direction.h"

#include <array>
#include <iostream>

Dungeon::Dungeon() = default;


void Dungeon::addRoom(std::shared_ptr<Room> room)
{
	std::cout << "add room > " << room << std::endl;
	rooms.push_back(std::move(room));
}

void Dungeon::printRoomList()
{
	for (int i = 0; i < rooms.size(); i++)
	{
		Room room = *rooms[i];
		std::cout << "room " << i + 1 << " --- " << room.getCoords().getX() << " : " << room.getCoords().getY() << std::endl;
		for (int j = 0; j < rooms.size(); j++)
		{
			Room secondRoom = *rooms[j];
			if (room.getCoords() + d.NORTH_DIRECTION_INCREMENT == secondRoom.getCoords())
			{
			std::cout << "neighbor at north" << std::endl;
			}			
			if (room.getCoords() + d.SOUTH_DIRECTION_INCREMENT == secondRoom.getCoords())
			{
			std::cout << "neighbor at south" << std::endl;
			}			
			if (room.getCoords() + d.EAST_DIRECTION_INCREMENT == secondRoom.getCoords())
			{
			std::cout << "neighbor at east" << std::endl;
			}			
			if (room.getCoords() + d.WEST_DIRECTION_INCREMENT == secondRoom.getCoords())
			{
			std::cout << "neighbor at west" << std::endl;
			}
		}

	}
}


std::vector<std::shared_ptr<Room>> Dungeon::getRoomPtrList()
{
	return rooms;
}

Room Dungeon::createTemporaryRoom(Room parentRoom, Vector2d direction)
{
	return parentRoom;
}

bool Dungeon::checkRoomNeighbors(Room newRoom)
{
	Vector2d newRoomCoords = newRoom.getCoords();
	// check 4 directions, ignore if direction is parentRoom;
	std::array<Vector2d, 4> temporaryNeighbors = createTemporaryNeighborsCoords(newRoomCoords);

	for (int neighborCoordsIteration = 0; neighborCoordsIteration < temporaryNeighbors.size(); neighborCoordsIteration++)
	{
		if (temporaryNeighbors[neighborCoordsIteration] == newRoom.getCoords())
		{
			break;
		}

		// if no neighbors for each direction, return true, else return false;
		for (int i = 0; i < rooms.size(); i++)
		{
			if (rooms[i]->getCoords() == temporaryNeighbors[neighborCoordsIteration])
			{
				return false;
			}
		}
		return true;
	}



}

std::shared_ptr<Room> Dungeon::generateRoom(std::shared_ptr<Room> room, int generationAge)
{
	// Check Neighbors
	if (checkRoomNeighbors(*room))
	{

	}
	// Check future room Neighbors

	// increment room in a temporary vector array

	return room;
}


std::vector<std::shared_ptr<Room>> Dungeon::roomsGeneration(std::shared_ptr<Room> parentRoom, int generationAge)
{
	return rooms;
}

std::array<Vector2d, 4> Dungeon::createTemporaryNeighborsCoords(Vector2d origin)
{
	std::array<Vector2d, 4> fourDirectionNeighbors
	{
		origin + d.NORTH_DIRECTION_INCREMENT,
		origin + d.SOUTH_DIRECTION_INCREMENT,
		origin + d.EAST_DIRECTION_INCREMENT,
		origin + d.WEST_DIRECTION_INCREMENT
	};
	return fourDirectionNeighbors;
}