#include "Dungeon.h"
#include "Direction.h"

Dungeon::Dungeon() = default;

void Dungeon::addRoom(std::unique_ptr<Room> room)
{
	rooms.push_back(std::move(room));
}

void Dungeon::printRoomList()
{
	for (int i = 0; i < rooms.size(); i++)
	{
		Room room = *rooms[i];
		std::cout << "room " << i + 1 << std::endl;
		std::cout << room.getCoords().getX() << " : " << room.getCoords().getY() << std::endl;
		if (room.getNeighbors().northNeighbor)
		{
			std::cout << "neighbor at north" << std::endl;
		}
		if (room.getNeighbors().southNeighbor)
		{
			std::cout << "neighbor at south" << std::endl;
		}
		if (room.getNeighbors().eastNeighbor)
		{
			std::cout << "neighbor at east" << std::endl;
		}
		if (room.getNeighbors().westNeighbor)
		{
			std::cout << "neighbor at west" << std::endl;
		}
	}

}

