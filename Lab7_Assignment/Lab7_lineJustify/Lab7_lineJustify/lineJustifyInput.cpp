// This program displays line justification
// 2/27/2020
// Antonio S.-M.

#include <iostream>
#include <string>
#include <cstdlib>
#include "lineJustify.hpp"
#include <ctime>

using std::cout; using std::cin; using std::string; using std::endl;

int main() {

	srand(time(nullptr));

	const int maxcharPerL = 75;
	const int mincharPerL = 40;

	cout << "Input a string:\n";
	string userString;
	getline(cin, userString);

	if (userString.size() < mincharPerL) {
		cout << "String of this size does not get justified.";
		cout << "\nsize: " << userString.size() << " characters";
		exit(1);
	}
	else 
		puncSpace(userString);
	

	if (userString.size() < maxcharPerL) 
		while (userString.size() < maxcharPerL) 
			wordSpace(userString);
		
	cout << "Your line justified:\n" << userString;
}