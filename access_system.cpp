#include <iostream>
#include "access_system.h"



//Implementing singleton
AccessSystem AccessSystem::sys = AccessSystem();



//There follows implementation of AccessSystem class

AccessSystem::AccessSystem() : logEnabled(true) {}

void AccessSystem::enableLog() {
	logEnabled = true;
}

void AccessSystem::disableLog() {
	logEnabled = false;
}

bool AccessSystem::checkAccess(User* user, Room* room) {
	bool resp = false;
	
	//First check processes access levels
	if (room->getAccessLevel() == AccessLevel::NO_LEVEL) {
		resp = room->isAllowed(user);
	} else {
		resp = room->getAccessLevel() <= user->getAccessibleLevel();
	}

	//Second check is in ban list or in white list
	if (resp) {
		resp = !room->isBanned(user);
	} else {
		resp = room->isAllowed(user);
	}
	
	//Doing log if it's needed
	if (logEnabled) {
		if (resp) {
			std::cout << user->getName() + " got access to room " + room->getName() << '\n';
		} else {
			std::cout << user->getName() + " didn't get access to room " + room->getName() << '\n';
		}
	}

	return resp;
}

bool AccessSystem::grantCustomAccess(User* user, Room* room) {

	//Disabling log temporary for internal access check
	disableLog();
	bool resp = checkAccess(user, room);
	enableLog();

	//Granting access only if needed
	if (!resp) {
		room->unbanUser(user);
		room->addUser(user);
	}

	if (logEnabled) {
		if (!resp) {
			std::cout << user->getName() + " was granted a custom access to room " + room->getName() << '\n';
		}
		else {
			std::cout << user->getName() + " already has an access to room " + room->getName() << '\n';
		}
	}
	return !resp;
}

bool AccessSystem::withdrawAccess(User* user, Room* room) {

	//Disabling log temporary for internal access check
	disableLog();
	bool resp = checkAccess(user, room);
	enableLog();

	//Withdrawing access only if it wasn't done yet
	if (resp) {
		room->removeUser(user);
		room->banUser(user);
	}

	if (logEnabled) {
		if (resp) {
			std::cout << user->getName() + " was banned from room " + room->getName() << '\n';
		}
		else {
			std::cout << user->getName() + " already doesn't have an access to room " + room->getName() << '\n';
		}
	}
	return resp;
}