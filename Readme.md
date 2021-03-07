# University access system

## Description

The program implements university access system, in fact, it is easily adjustable for your own needs.

By default program supports:

1. 5 classes representing types of users
2. 5 classes representing types of rooms
3. 4 types of access levels

Any of the abovementioned is easily expandable.

## Installation

You will need to build the program from source code.

In order to run the program you need to provide two databases:

1. User database (you can replace the default one named `database.txt` consisting of 60 users)
2. Room database (you can replace the default one named `room-database.txt` consisting of 47 rooms)

Make sure to follow the name convention and the structure:

1. For `database.txt`:

    ```cpp
    {
       {
          name,
          occupation,
          subject,
          age,
          subjectYears
       },
       {
          name,
          occupation,
          subject,
          age,
          subjectYears
       },
    	 //...
    }
    ```

2. For `room-database.txt`:

    ```cpp
    {
       name,
       name,
    	 //...
    }
    ```

## How to run

You should double check the correctness of your databases, then initialize them:

```cpp
Users::initialize();
Rooms::initialize();
```

Now the Access System is ready to use.

Primary methods that you will use have the following signatures:

```cpp
class User {
	public:
		void goToRoom(Room* room);
		virtual void allowUser(User* user, Room* room);
		virtual void forbidUser(User* user, Room* room);
}
```

## Other information

This is not stable release of a program. You are running this program at your own risk.

Copyright 2021. All rights reserved.