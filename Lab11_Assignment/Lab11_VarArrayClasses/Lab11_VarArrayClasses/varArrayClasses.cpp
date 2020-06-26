// Dynamically allocated classes
// Antonio S.-M.
// 4/16/2020

#include <iostream>
#include "vararray.hpp"

using std::cout; using std::endl; using std::cin;

int main() {

	varArray userAr;
	char op;
	double number;

	cout << "enter operation [a/r/q] and number: ";
	cin >> op;

	while (op != 'q' && op != 'Q') {
		cin >> number;

		if (op == 'a' || op == 'A')
			userAr.addNumber(number);
		else if (op == 'r' || op == 'R')
			userAr.removeNumber(number);

		userAr.output();

		cout << "enter operation [a/r/q] and number: ";
		cin >> op;
	}

}