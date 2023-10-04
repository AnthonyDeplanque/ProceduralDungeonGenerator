#pragma once
#include <iostream>
#include <vector>

#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	void addRoom(std::shared_ptr<Room> room);
	void printRoomList();

	std::vector<std::shared_ptr<Room>> getRoomPtrList();

	//inline std::vector<std::shared_ptr<Room>> getRooms() {} ;
private:
	std::vector<std::shared_ptr<Room>> rooms{};
};

