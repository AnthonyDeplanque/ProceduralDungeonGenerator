#include <iostream>
#include <vector>
#include "Dungeon.h"
#include "Direction.h"

int main()
{

	Dungeon dungeon;

	dungeon.addRoom(std::make_shared<Room>(Room(0, 0, 0)));

	std::shared_ptr<Room> dungeonRoom = dungeon.getRoomPtrList()[0];

	for (int i = 0; i <4; i++)
	{
		dungeon.generateRoomsByLastGeneratedRooms(i);
	}

	dungeon.printRoomList();


	return EXIT_SUCCESS;
}
