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

void Dungeon::printRoomList(bool neighbors)
{
	for (int i = 0; i < rooms.size(); i++)
	{
		Room firstRoom = *rooms[i];
		std::cout << "room " << i + 1 << " --- " << firstRoom.getCoords().getX() << " : " << firstRoom.getCoords().getY() << " --- ";
		std::cout << "age : " << firstRoom.getAge() << std::endl;
		if (neighbors)
		{
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
	return Room(roomCoords, 0);
}

// Checks neighbors of the future room, returns true if it can be created (no neighbors excepts parent room)
bool Dungeon::checkRoomNeighbors(Vector2d newRoomCoords)
{
	// std::cout<< "new room coords -- "<< newRoomCoords.getX() << " : " << newRoomCoords.getY() << std::endl;
	// check 4 directions, ignore if direction is parentRoom;
	std::vector<Vector2d> temporaryNeighbors = createTemporaryNeighborsCoords(newRoomCoords);

	for (int i = 0; i < temporaryNeighbors.size(); i++)
	{

		Vector2d secondRoomCoords = temporaryNeighbors[i];

		// if no neighbors for each direction, return true, else return false;
		for (int j = 0; j < rooms.size(); j++)
		{
			if (rooms[j]->getCoords() == temporaryNeighbors[i])
			{
				std::cout << "There's a neighbor for temp room !! abort!" << std::endl;
				return false;
			}
		}
		return true;
	}
}

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
		Vector2d potentiallyAddableRoom = temporaryNeighbors[i];

		bool addRoomCoords = true;
		// If room already exist, skip
		for (int j = 0; j < rooms.size(); j++)
		{
			Room& roomToCheck = *rooms[j];

			if (roomToCheck.getCoords() == potentiallyAddableRoom)
			{
				std::cout << "already exist" << std::endl;
				addRoomCoords = false;
			}
			if (addRoomCoords) {
				std::cout << "added room coords to potentially addable rooms coords" << std::endl;
				potentiallyAddableRoomsCoords.push_back(std::make_shared<Vector2d>(potentiallyAddableRoom));
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
	{

		// Check Future room Neighbors
		if (checkRoomNeighbors(*potentiallyFutureRooms[i]))
		{
			//create new temporary room
			Room newRoom = createTemporaryRoom(*potentiallyFutureRooms[i]);
			std::cout << "create new temporary room " << newRoom.getCoords().getX() << ":" << newRoom.getCoords().getY() << std::endl;
			// Push to temp array
			temporaryRooms.push_back(std::move(std::make_shared<Room>(newRoom)));
		}

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
		int generationNumber = floor(basicGenerationCount + ((generationAge / 3) - 1));
		if (generationNumber < 0) generationNumber = 0;
		if (generationNumber >= roomVectorSize) generationNumber = roomVectorSize - 1;

		std::random_device generator;
		std::vector<int> roomIndexesGenerated;

		// Here assign roomIndexGenerated

		for (int i = 0; i < generationNumber; i++)
		{

			// Here we have got a Out Of Range Vector

			std::uniform_int_distribution<int> roomIndexToGenerate = std::uniform_int_distribution<int>{ 0, roomVectorSize };

			int roomIndex = roomIndexToGenerate(generator);
			std::cout << "room index : " << roomIndex << std::endl;


			std::cout << "room index generated : ";
			for (int j = 0; j < roomIndexesGenerated.size(); j++)
			{
				std::cout << roomIndexesGenerated[j] << " ";
			}
			std::cout << std::endl;


			auto find = std::find(roomIndexesGenerated.begin(), roomIndexesGenerated.end(), roomIndex);

			if (find == roomIndexesGenerated.end())
			{
				roomIndexesGenerated.push_back(roomIndex);

			}

		}

		clearLastGenerationRooms();
		// NO LAST GENERATION ROOMS
		for (int i = 0; i < roomIndexesGenerated.size(); i++)
		{

			// HERE IT IS !!! THE PROBLEM !!
			addRoom(temporaryRooms[roomIndexesGenerated[i]]);


			lastGenerationRooms.push_back(temporaryRooms[roomIndexesGenerated[i]]);

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
	if (getLastGenerationRoomsPtr().size() != 0)
	{

		std::cout << getLastGenerationRoomsPtr().size() << " last generated rooms" << std::endl;
		for (int i = 0; i < getLastGenerationRoomsPtr().size(); i++)
		{
			auto lastRoom = getLastGenerationRoomsPtr()[i];
			generateRooms(lastRoom, generationAge);
		}
	}
	else
	{
		auto room = rooms[0];
		generateRooms(room, generationAge);
	}


	// clear temporary rooms

}

