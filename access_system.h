#pragma once
#include <vector>
#include "users.h"
#include "rooms.h"

class AccessSystem {
	bool logEnabled;

	//Constructor is private but callable in static member initialization
	//Perfect for singleton
	AccessSystem();

public:

	static AccessSystem sys;

	void enableLog();
	void disableLog();
	bool checkAccess(User* user, Room* room);
	bool grantCustomAccess(User* user, Room* room);
	bool withdrawAccess(User* user, Room* room);
};