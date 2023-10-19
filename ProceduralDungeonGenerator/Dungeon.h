#pragma once
#include <iostream>
#include <vector>
#include "DirectionIncrementation.h"
#include "Room.h"
#include "Vector2d.h"

class Dungeon
{
public:
	Dungeon();
	void addRoom(std::shared_ptr<Room> room);
	void printRoomList(bool neighbors=false);

	std::vector<std::shared_ptr<Room>> getRoomPtrList();
	void generateRooms(std::shared_ptr<Room> room, int generationAge);

	std::vector<std::shared_ptr<Room>> getLastGenerationRoomsPtr();
	void generateRoomsByLastGeneratedRooms(int generationAge);


private:
	Room createTemporaryRoom(Vector2d roomCoords);
	std::vector<Vector2d> createTemporaryNeighborsCoords(Vector2d origin);
	bool checkRoomNeighbors(Vector2d newRoomCoords); // return true if no neighbors except parent room for the future room
	bool checkDirectionnalNeighbor(Room firstRoom, Room secondRoom, Vector2d direction);
	std::vector<std::shared_ptr<Vector2d>> prepareFutureRooms(Room &parentRoom);

	void clearLastGenerationRooms();


	DirectionIncrementation d;
	std::vector<std::shared_ptr<Room>> rooms{}; // Generated rooms
	std::vector<std::shared_ptr<Room>> temporaryRooms{}; // Temp rooms
	std::vector<std::shared_ptr<Room>> lastGenerationRooms{}; // Rooms generated from the last generation
};

