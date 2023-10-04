#include <iostream>
#include "Dungeon.h"

int main()
{
	int const LIMIT_X = 20;
	int const LIMIT_Y = 20;

	Room firstRoom(LIMIT_X / 2, LIMIT_Y / 2);
	Dungeon dungeon;

	dungeon.addRoom(std::make_unique<Room>(firstRoom));
	dungeon.addRoom(std::make_unique<Room>(Room(Direction::NORTH, *dungeon.getRooms()[0])));
	dungeon.addRoom(std::make_unique<Room>(Room(Direction::SOUTH, *dungeon.getRooms()[0])));
	dungeon.printRoomList();
}
