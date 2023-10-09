#include "Dungeon.h"
#include "Direction.h"
#include "DirectionIncrementation.h"
#include <array>
#include <iostream>

DirectionIncrementation d;

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
		std::cout << "room " << i + 1 << std::endl;
		std::cout << room.getCoords().getX() << " : " << room.getCoords().getY() << std::endl;
		if (room.getNeighbors()->northNeighbor)
		{
			std::cout << "neighbor at north" << std::endl;
		}
		if (room.getNeighbors()->southNeighbor)
		{
			std::cout << "neighbor at south" << std::endl;
		}
		if (room.getNeighbors()->eastNeighbor)
		{
			std::cout << "neighbor at east" << std::endl;
		}
		if (room.getNeighbors()->westNeighbor)
		{
			std::cout << "neighbor at west" << std::endl;
		}
	}
}

std::vector<std::shared_ptr<Room>> Dungeon::getRoomPtrList()
{
	return rooms;
}

Room Dungeon::createTemporaryRoom(Room parentRoom, Vector2d direction)
{

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

	
}


std::vector<std::shared_ptr<Room>> Dungeon::roomsGeneration(std::shared_ptr<Room> parentRoom, int generationAge)
{

}

std::array<Vector2d, 4> Dungeon::createTemporaryNeighborsCoords(Vector2d origin)
{
	Vector2d fourDirectionNeighbors[4]
	{
		origin + d.NORTH_DIRECTION_INCREMENT,
		origin + d.SOUTH_DIRECTION_INCREMENT,
		origin + d.EAST_DIRECTION_INCREMENT,
		origin + d.WEST_DIRECTION_INCREMENT
	};
}