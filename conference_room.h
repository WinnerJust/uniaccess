#pragma once
#include "access_level.h"

class ConferenceRoom : public Room {
public:
	ConferenceRoom(std::string name) : Room(name, AccessLevel::RED) {}
};