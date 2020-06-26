// function definitions

#include "battleship.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

void initialize(Ship Fleet[]) {

	for (int ship = 0; ship < fleetSize; ++ship) {
		Fleet[ship].loc.x = -1;
		Fleet[ship].loc.y = '*';
	}
}

Location pick() {
	Location Ship;
	Ship.x = rand() % 6 + 1;
	int y = rand() % 6 + 1;

	switch (y) {

	case 1:
		Ship.y = 'a';
		break;
	case 2:
		Ship.y = 'b';
		break;
	case 3:
		Ship.y = 'c';
		break;
	case 4:
		Ship.y = 'd';
		break;
	case 5:
		Ship.y = 'e';
		break;
	case 6:
		Ship.y = 'f';
		break;
	}

	return Ship;
}

bool match(const Ship& Ship, const Location& Position) {
	if (Ship.loc.x == Position.x
		&& Ship.loc.y == Position.y)
		return true;
	else
		return false;
}

int check(const Ship Fleet[], const Location& Position) {
	for (int ship = 0; ship < fleetSize; ++ship)
		if (match(Fleet[ship], Position)) {
			return ship;
		}
	return -1;
}

void deploy(Ship Fleet[]) {

	int Ship = 0;

	while (Ship < fleetSize) {
		Location Position = pick();
		int tmp = check(Fleet, Position);

		if (tmp == -1) {
			Fleet[Ship].loc = Position;
			Fleet[Ship].sunk = false;
			++Ship;
		}

	}
}

void printShip(const Ship& Ship) {

	cout << "Ship x-location: " << Ship.loc.x << endl
		<< "Ship y-location: " << Ship.loc.y << endl;

	if (Ship.sunk)
		cout << "This ship has been sank!" << endl;
	else
		cout << "This ship has not been sank!" << endl;

}

void printFleet(const Ship Fleet[]) {

	int ship = 0;

	while (ship < fleetSize) {
		printShip(Fleet[ship]);
		++ship;
	}

}

bool operational(const Ship Fleet[]) {

	for (int ship = 0; ship < fleetSize; ++ship) {

		if (Fleet[ship].sunk == false)
			return true;
	}

	return false;

}

Location fire() {

	cout << "\nEnter the coordinates of your shot: ";
	Location shot;
	cin >> shot.x >> shot.y;

	return shot;
}

void sink(Ship& Ship) {

	Ship.sunk = true;

}