#include "rooms.h"

//Including raw data about rooms from outside rather than storing it here
//In order not to make a mess in .cpp file
std::vector<std::string> Rooms::roomsRaw
#include "room-database.txt"
;

//Main room database which should be initialized
std::vector<Room*> Rooms::database;


//Implementation of single method in Rooms class which fill the database
void Rooms::initialize() {
	for (auto& room : roomsRaw) {
		if (room.find("Lecture Room") != -1 && room.find("University Room #3") == -1) {
			Rooms::database.push_back(new LectureRoom(room));
		}
		else if (room.find("Lecture Room") != -1) {
			Rooms::database.push_back(new ClassRoom(room));
		}
		else {
			Rooms::database.push_back(new ConferenceRoom(room));
		}
	}
}