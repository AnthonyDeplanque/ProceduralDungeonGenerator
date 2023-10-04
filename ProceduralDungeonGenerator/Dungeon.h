#pragma once
#include <iostream>
#include <vector>

#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	void addRoom(std::unique_ptr<Room> room);
	void printRoomList();
	void checkNeighborRooms(Room* room);
	std::vector<std::unique_ptr<Room>> getRooms();
private:
	std::vector<std::unique_ptr<Room>> rooms;
};

