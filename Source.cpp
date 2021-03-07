#include "access_system.h"

void testCase1() {
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->forbidUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);
}

void testCase2() {
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->forbidUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->allowUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);
}

void testCase3() {
	Users::database[1]->goToRoom(Rooms::database[0]);
	Users::database[2]->allowUser(Users::database[1], Rooms::database[0]);
	Users::database[1]->goToRoom(Rooms::database[0]);

	Users::database[1]->goToRoom(Rooms::database[10]);
	Users::database[1]->goToRoom(Rooms::database[20]);
	Users::database[1]->goToRoom(Rooms::database[30]);

	Users::database[2]->forbidUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);

	Users::database[2]->forbidUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);

	Users::database[5]->allowUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);
}

void testCase4() {
	Users::database[50]->goToRoom(Rooms::database[0]);

	Users::database[2]->forbidUser(Users::database[50], Rooms::database[0]);
	Users::database[50]->goToRoom(Rooms::database[0]);

	Users::database[5]->allowUser(Users::database[50], Rooms::database[0]);
	Users::database[50]->goToRoom(Rooms::database[0]);
}

void testCase5() {
	Users::database[59]->goToRoom(Rooms::database[36]);

	Users::database[2]->forbidUser(Users::database[59], Rooms::database[36]);
	Users::database[59]->goToRoom(Rooms::database[36]);

	Users::database[5]->allowUser(Users::database[59], Rooms::database[36]);
	Users::database[59]->goToRoom(Rooms::database[36]);
}


void testCase6() {
	Users::database[50]->goToRoom(Rooms::database[36]);
	Users::database[2]->forbidUser(Users::database[50], Rooms::database[36]);
	Users::database[50]->goToRoom(Rooms::database[36]);
	Users::database[2]->allowUser(Users::database[50], Rooms::database[36]);
	Users::database[50]->goToRoom(Rooms::database[36]);

	Users::database[50]->forbidUser(Users::database[50], Rooms::database[36]);
}



int main() {
	//These are required before using Access System
	Users::initialize();
	Rooms::initialize();
	
	//You can try 1-6 example cases
	testCase5();

	return 0;
}