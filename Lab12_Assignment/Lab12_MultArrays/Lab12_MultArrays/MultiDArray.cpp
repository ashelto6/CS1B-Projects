// Using Multidimentional arrays to print shots on grid
// Antonio S.-M.
// 4/24/2020

#include <iostream>

using std::cin; using std::cout;

// size of the ocean
const int oceanLength = 6;
const int oceanWidth = 6;

int convert(const char&); // converts a value of char to a value of int, returns int value
int main() {
	bool shots[oceanLength][oceanWidth];
	char x;
	int y, z;
	char reShoot;

	cout << "Another shot? [y/n] ";
	cin >> reShoot;

	while (reShoot == 'y' || reShoot == 'Y') {
		cout << "Location? ";
		cin >> x >> y;
		z = convert(x);
		shots[z][y - 1] = false;

		cout << "All fired shots\n"
		<< "  a b c d e f";
		for (int i = 0; i < oceanLength; ++i) {
			cout << "\n" << i + 1;
			for (int j = 0; j < oceanWidth; ++j) {
				if (!(shots[j][i])) {
					cout << " *";
				}
				else
					cout << "  ";
			}
		}
		cout << "\nAnother shot? [y/n] ";
		cin >> reShoot;
	}
}
int convert(const char& x) {
	int z = -1;

	switch (x) {

	case 'a':
		z = 0;
		break;
	case 'b':
		z = 1;
		break;
	case 'c':
		z = 2;
		break;
	case 'd':
		z = 3;
		break;
	case 'e':
		z = 4;
		break;
	case 'f':
		z = 5;
		break;
	}

	return z;

}