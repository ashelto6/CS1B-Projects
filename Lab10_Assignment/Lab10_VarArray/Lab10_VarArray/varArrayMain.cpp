// manipulates numbers in an array using Dynamic Memory Allocation
// Antonio S.-M.
// 3/29/2020

#include "varArray.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	int size = 0;
	double* a = new double[size];
	char op;
	double number;

	cout << "enter operation [a/r/q] and number: ";
	cin >> op;

	while (op != 'q' && op != 'Q') {
		cin >> number;

		if (op == 'a')
			addNumber(a, number, size);
		else if (op == 'r')
			removeNumber(a, number, size);

		output(a, size);

		cout << "enter operation [a/r/q] and number: ";
		cin >> op;
	}
	delete[] a;
}