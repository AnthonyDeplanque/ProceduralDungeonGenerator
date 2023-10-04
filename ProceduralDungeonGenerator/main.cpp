#include <iostream>
#include "Dungeon.h"
#include "Direction.h"

int main()
{

	int const LIMIT_X = 20;
	int const LIMIT_Y = 20;

	Room firstRoom(LIMIT_X / 2, LIMIT_Y / 2);
	Dungeon dungeon;

	dungeon.addRoom(std::make_unique<Room>(firstRoom));
	dungeon.addRoom(std::make_unique<Room>(Direction::NORTH,firstRoom));
	dungeon.addRoom(std::make_unique<Room>(Direction::SOUTH,firstRoom));

	dungeon.printRoomList();
}
