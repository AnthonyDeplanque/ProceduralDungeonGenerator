#include <iostream>
#include <vector>
#include "Dungeon.h"
#include "Direction.h"

int main()
{
	int ageToGenerate = 1;
	int xOrigin = 0;
	int yOrigin = 0;
	bool DEBUG = true;

	Dungeon dungeon;

	dungeon.addRoom(std::make_shared<Room>(Room(xOrigin, yOrigin, 0)));

	std::shared_ptr<Room> dungeonRoom = dungeon.getRoomPtrList()[0];

	for (int i = 0; i < ageToGenerate; i++)
	{
		dungeon.generateRoomsByLastGeneratedRooms(i);
	}

	if (DEBUG)
	{
		dungeon.printRoomList();
	}

	return EXIT_SUCCESS;
}
