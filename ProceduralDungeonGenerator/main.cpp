#include <iostream>
#include <vector>
#include "Dungeon.h"
#include "Direction.h"

int main()
{




	Dungeon dungeon;

	dungeon.addRoom(std::make_shared<Room>(Room(0, 0)));

	std::shared_ptr<Room> dungeonRoom = dungeon.getRoomPtrList()[0];

//	dungeon.addRoom(std::make_shared<Room>(Direction::NORTH, dungeonRoom.get()));
//	dungeon.addRoom(std::make_shared<Room>(Direction::EAST, dungeonRoom.get()));

	for (int i = 0; i < 1; i++)
	{

	dungeon.generateRoomsByLastGeneratedRooms(i);
	}
	
	dungeon.printRoomList();


	return EXIT_SUCCESS;
}
