#pragma once
#include "access_level.h"

class LectureRoom : public Room {
public:
	LectureRoom(std::string name) : Room(name, AccessLevel::YELLOW) {}
};