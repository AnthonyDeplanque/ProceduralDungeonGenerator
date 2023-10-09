#include <iostream>
#include <vector>
#include "Dungeon.h"
#include "Direction.h"

int main()
{

	int const LIMIT_X = 20;
	int const LIMIT_Y = 20;

	Room firstRoom(LIMIT_X / 2, LIMIT_Y / 2);
	Dungeon dungeon;

	dungeon.addRoom(std::make_shared<Room>(firstRoom));


	std::shared_ptr<Room> dungeonRoom = dungeon.getRoomPtrList()[0];

//	dungeon.addRoom(std::make_shared<Room>(Direction::NORTH, dungeonRoom.get()));
//	dungeon.addRoom(std::make_shared<Room>(Direction::EAST, dungeonRoom.get()));

	for (int i = 0; i < 2; i++) {
		dungeon.generateRoomsByLastGeneratedRooms(i);
	}

	dungeon.printRoomList();


	return EXIT_SUCCESS;
}
