// plays battleShip game
// Antonio S.-M.
// 3/18/2020

#include "battleship.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

int main() {

	srand(time(nullptr));

	cout << "LET'S PLAY BATTLESHIP!\n";
	Ship Fleet[fleetSize];

	initialize(Fleet);

	deploy(Fleet);

	cout << "Press [v] to view ship locations after every shot! (press any key to BYPASS): ";
	char view;
	cin >> view;

	if (view == 'v' || view == 'V')
		printFleet(Fleet);

	Location target;
	int hit;
	while (operational(Fleet)) {

		target = fire();

		hit = check(Fleet, target);

		if (hit != -1) {

			sink(Fleet[hit]);
			cout << "\nThat's a hit!\n\n";
			if (view == 'v' || view == 'V')
				printFleet(Fleet);
		}
		else {
			cout << "\nThat's a miss!\n\n";
			if (view == 'v' || view == 'V')
				printFleet(Fleet);
		}
	}

	cout << "\nGame Over! All Ships Sank!\n";
}