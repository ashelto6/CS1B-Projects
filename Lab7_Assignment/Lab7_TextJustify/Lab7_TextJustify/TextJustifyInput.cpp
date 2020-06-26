// text justification with IOfiles and strings
// 2/28/2020
// Antonio S.-M.

#include <iostream> 
#include <string>
#include <cstdlib>
#include "TextJustify.hpp"
#include <ctime>
#include <fstream>

using std::cout; using std::endl;  using std::ifstream; using std::ofstream; using std::string;

int main() {

	srand(time(nullptr));

	ofstream fout;
	fout.open("justified.txt");
	if (fout.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	ifstream fin;
	fin.open("unjustified.txt"); // opens textfile
	if (fin.fail()) {
		cout << "Error opening file" << endl;
		exit(1);
	}

	const int maxcharPerL = 75;
	const int mincharPerL = 40;
	string userString;

	for (int i = 0; getline(fin, userString); ++i) { // each iteration a new line is taken from the input stream file (fin), assigned to variable userString
			puncSpace(userString);

		if (userString.size() < maxcharPerL && userString.size() > mincharPerL) 
			while (userString.size() < maxcharPerL) 
				wordSpace(userString);

		fout << userString << endl; // prints each line of input stream file to output stream file (fout)
	}

	fout.close();
	fin.close();
	cout << "File has been updated.\n";
}
