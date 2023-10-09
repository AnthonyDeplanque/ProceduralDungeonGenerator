#pragma once
#include <iostream>
#include <vector>

#include "Room.h"
#include "Vector2d.h"

class Dungeon
{
public:
	Dungeon();
	void addRoom(std::shared_ptr<Room> room);
	void printRoomList();

	std::vector<std::shared_ptr<Room>> getRoomPtrList();
	std::shared_ptr<Room> generateRoom(std::shared_ptr<Room> room, int generationAge);
	std::vector<std::shared_ptr<Room>> roomsGeneration(std::shared_ptr<Room> room, int generationAge);

	//inline std::vector<std::shared_ptr<Room>> getRooms() {} ;
private:
	Room createTemporaryRoom(Room parentRoom, Vector2d direction);
	std::array<Vector2d, 4> createTemporaryNeighborsCoords(Vector2d origin);
	bool checkRoomNeighbors(Room newRoom); // return true if no neighbors except parent room for the future room
	
	std::vector<std::shared_ptr<Room>> rooms{};
	std::vector<std::shared_ptr<Room>> temporaryRooms{};
};

