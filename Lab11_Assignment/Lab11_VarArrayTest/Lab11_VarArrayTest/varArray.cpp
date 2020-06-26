// function definitions

#include <iostream>
#include "vararray.hpp"

using std::cout; using std::endl;

int varArray::check(double number) {

	for (int i = 0; i < size_; ++i)
		if (number == array_[i])
			return i;

	return -1;
}

void varArray::addNumber(double number) {

	if (check(number) == -1) {

		++size_;
		double* array2 = new double[size_];
		for (int i = 0; i < size_ - 1; ++i)
			array2[i] = array_[i];
		array2[size_ - 1] = number;

		delete[] array_;
		array_ = array2;
	}
}

void varArray::removeNumber(double number) {

	if (check(number) != -1) {

		--size_;
		double* array2 = new double[size_];
		bool found = false;


		for (int i = 0; i < size_; ++i) {

			if (array_[i] == number)
				found = true;

			if (!(found)) {
				array2[i] = array_[i];
			}
			else {
				array2[i] = array_[i + 1];
			}
		}

		delete[] array_;
		array_ = array2;
	}
}

void varArray::output() {
	//cout << "your numbers: ";
	for (int i = 0; i < size_; ++i)
		cout << array_[i] << " ";
	cout << endl;
}

varArray::varArray(const varArray& oldObj) {

	size_ = oldObj.size_;
	array_ = new double[size_];

	for (int i = 0; i < size_; ++i)
		array_[i] = oldObj.array_[i];
}

varArray& varArray:: operator=(const varArray& oldObj) {

	if (this != &oldObj) {
		size_ = oldObj.size_;
		delete[] array_;
		array_ = new double[size_];

		for (int i = 0; i < size_; ++i)
			array_[i] = oldObj.array_[i];
	}

	return *this;
}
