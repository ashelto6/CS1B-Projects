//function definitions

#include <iostream>

using std::cout; using std::cin; using std::endl;

void output(double* arrayPtr, int size) {

	for (int i = 0; i < size; ++i)
		cout << arrayPtr[i] << endl;
}

int check(double* arrayPtr, double number, int size) {

	for (int i = 0; i < size; ++i)
		if (number == arrayPtr[i])
			return i;

	return -1;
}

void addNumber(double*& arrayPtr, double number, int& size) {

	if (check(arrayPtr, number, size) == -1) {

		++size;
		double* arrayPtr2 = new double[size];

		for (int i = 0; i < size - 1; ++i)
			arrayPtr2[i] = arrayPtr[i];
		arrayPtr2[size - 1] = number;

		delete[] arrayPtr;
		arrayPtr = arrayPtr2;
	}
}

void removeNumber(double*& arrayPtr, double number, int& size) {

	int index = check(arrayPtr, number, size);
	if (index != -1) {
		--size;
		double* arrayPtr2 = new double[size];
		bool found = false;

		for (int i = 0; i < size; ++i) {

			if (arrayPtr[i] == number)
				found = true;

			if (!(found)) {
				arrayPtr2[i] = arrayPtr[i];
			}
			else {
				arrayPtr2[i] = arrayPtr[i+1];
			}
		}

		delete[] arrayPtr;
		arrayPtr = arrayPtr2;
	}

}

