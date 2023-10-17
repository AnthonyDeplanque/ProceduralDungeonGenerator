#include "Dungeon.h"
#include "Direction.h"

#include <array>
#include <iostream>
#include <random>

Dungeon::Dungeon() = default;

// add manually a room
void Dungeon::addRoom(std::shared_ptr<Room> room)
{
	std::cout << "add room > " << room << std::endl;
	rooms.push_back(std::move(room));
}

std::vector<std::shared_ptr<Room>> Dungeon::getLastGenerationRoomsPtr()
{
	return this->lastGenerationRooms;
}

void Dungeon::printRoomList()
{
	for (int i = 0; i < rooms.size(); i++)
	{
		Room firstRoom = *rooms[i];
		std::cout << "room " << i + 1 << " --- " << firstRoom.getCoords().getX() << " : " << firstRoom.getCoords().getY() << std::endl;
		for (int j = 0; j < rooms.size(); j++)
		{
			Room secondRoom = *rooms[j];

			if (checkDirectionnalNeighbor(firstRoom, secondRoom, d.NORTH_DIRECTION_INCREMENT)) std::cout << "neighbor at north" << std::endl;
			if (checkDirectionnalNeighbor(firstRoom, secondRoom, d.SOUTH_DIRECTION_INCREMENT)) std::cout << "neighbor at south" << std::endl;
			if (checkDirectionnalNeighbor(firstRoom, secondRoom, d.EAST_DIRECTION_INCREMENT)) std::cout << "neighbor at east" << std::endl;
			if (checkDirectionnalNeighbor(firstRoom, secondRoom, d.WEST_DIRECTION_INCREMENT)) std::cout << "neighbor at west" << std::endl;

		}

	}
}

bool Dungeon::checkDirectionnalNeighbor(Room firstRoom, Room secondRoom, Vector2d direction)
{
	return ((firstRoom.getCoords() + direction) == secondRoom.getCoords());
}

std::vector<std::shared_ptr<Room>> Dungeon::getRoomPtrList()
{
	return rooms;
}

Room Dungeon::createTemporaryRoom(Vector2d roomCoords)
{
	return Room(roomCoords);
}


// Checks neighbors of the future room, returns true if it can be created (no neighbors excepts parent room)
bool Dungeon::checkRoomNeighbors(Vector2d newRoomCoords)
{
	// check 4 directions, ignore if direction is parentRoom;
	std::vector<Vector2d> temporaryNeighbors = createTemporaryNeighborsCoords(newRoomCoords);

	for (int i = 0; i < temporaryNeighbors.size(); i++)
	{
		Vector2d secondRoomCoords = temporaryNeighbors[i];

		//if parent's coords
		if (secondRoomCoords == newRoomCoords)
		{
			break;
		}

		// if no neighbors for each direction, return true, else return false;
		for (int j = 0; j < rooms.size(); j++)
		{
			if (rooms[j]->getCoords() == temporaryNeighbors[i])
			{
				return false;
			}
		}
		return true;
	}



}


//OK
std::vector<Vector2d> Dungeon::createTemporaryNeighborsCoords(Vector2d origin)
{

	std::vector<Vector2d> fourDirectionNeighbors
	{
		(origin + d.NORTH_DIRECTION_INCREMENT),
		(origin + d.SOUTH_DIRECTION_INCREMENT),
		(origin + d.EAST_DIRECTION_INCREMENT),
		(origin + d.WEST_DIRECTION_INCREMENT)
	};

	return fourDirectionNeighbors;
}

std::vector<std::shared_ptr<Vector2d>> Dungeon::prepareFutureRooms(Room& parentRoom)
{
	Vector2d parentRoomCoords = parentRoom.getCoords();

	// check 4 directions
	std::vector<Vector2d> temporaryNeighbors = createTemporaryNeighborsCoords(parentRoomCoords);
	std::vector<std::shared_ptr<Vector2d>> potentiallyAddableRoomsCoords;

	for (int i = 0; i < temporaryNeighbors.size(); i++)
	{
		bool addRoomCoords = true;
		// If room already exist, skip
		for (int j = 0; j < rooms.size(); j++)
		{
			Room& roomToCheck = *rooms[j];
			if (roomToCheck.getCoords() == temporaryNeighbors[i])
			{
				addRoomCoords = false;
			}
			if (addRoomCoords) {
				potentiallyAddableRoomsCoords.push_back(std::make_shared<Vector2d>(temporaryNeighbors[i]));
			}
		}
	}
	return potentiallyAddableRoomsCoords;
}

void Dungeon::generateRooms(std::shared_ptr<Room> room, int generationAge)
{
	// check neighbors to know where can room be created
	Room parentRoom = *room;

	std::vector<std::shared_ptr<Vector2d>> potentiallyFutureRooms = prepareFutureRooms(parentRoom);

	for (int i = 0; i < potentiallyFutureRooms.size(); i++)

		// Check Future room Neighbors
		if (checkRoomNeighbors(*potentiallyFutureRooms[i]))
		{
			//create new temporary room
			Room newRoom = createTemporaryRoom(*potentiallyFutureRooms[i]);
			// Push to temp array
			temporaryRooms.push_back(std::move(std::make_shared<Room>(newRoom)));
		}

	for (int i = 0; i < temporaryRooms.size(); i++)
	{
		Room room = *temporaryRooms[i];
		std::cout << room.getCoords().getX() << ":" << room.getCoords().getY() << std::endl;
	}


	// if no generation Age, push all temp rooms in generated rooms
	if (generationAge == 0)
	{

		rooms.insert(rooms.end(), temporaryRooms.begin(), temporaryRooms.end());

	}

	// Else, we randomly select created ones
	else
	{

		int roomVectorSize = temporaryRooms.size();
		int basicGenerationCount = 3;
		if (basicGenerationCount > roomVectorSize)
		{
			basicGenerationCount = roomVectorSize;
		}
		// We maxx the basic generation count to 3. it will increment every 3 rooms;
		int generationCount = floor(basicGenerationCount + (generationAge / 3));
		std::random_device generator;
		std::vector<int> roomIndexGenerated;

		for (int i = 0; i < generationCount; i++) {
			bool isGenerated = false;
			while (isGenerated == false)
			{
				// THIS IS WHERE THE FUN BEGINS ...
				// SURELY There is an infinite loop
				std::uniform_int_distribution<int> roomIndexToGenerate = std::uniform_int_distribution<int>{ 0, roomVectorSize };
				
				int roomIndex = roomIndexToGenerate(generator);
				auto find = std::find(roomIndexGenerated.begin(), roomIndexGenerated.end(), roomIndex);
				
				if (find != roomIndexGenerated.end())
				{
					roomIndexGenerated.push_back(roomIndex);
					isGenerated = true;
				}

			}

		}
			clearLastGenerationRooms();
		for (int i = 0; i < roomIndexGenerated.size(); i++)
		{
			addRoom(temporaryRooms[roomIndexGenerated[i]]);
			lastGenerationRooms.push_back(temporaryRooms[roomIndexGenerated[i]]);
		}

	}
	temporaryRooms.clear();
}

void Dungeon::clearLastGenerationRooms()
{
	lastGenerationRooms.clear();
}


void Dungeon::generateRoomsByLastGeneratedRooms(int generationAge)
{
	if (getLastGenerationRoomsPtr().size() != 0) {
		
		for (int i = 0; i < getLastGenerationRoomsPtr().size(); i++)
		{
		auto lastRoom = getLastGenerationRoomsPtr()[i];
		generateRooms(lastRoom, generationAge);
		}
	}
	else {
		auto room = rooms[0];
		generateRooms(room, generationAge);
	}

	
	// clear temporary rooms

}

