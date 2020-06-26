#include <iostream>
#include <string>
#include <cstdlib>


using std::string;

const int max = 75;

void puncSpace(string& line) {
	
	int indPos = line.find_first_of(".,!?;");

	while (indPos != string::npos && line.size() < max) {

		if (indPos != line.size() - 1) {
			line.insert(++indPos, " ");
			indPos = line.find_first_of(".,!?;", indPos + 2);
		}

		if (indPos == line.size() - 1)
			break;
	}
}

void wordSpace(string& line) {

	int indPos = 0;

	while (line.size() < max) {

		int randNum = rand() % line.size();
		indPos = line.find_first_of(' ', randNum);

		if (indPos < line.size() && indPos != string::npos) {
			line.insert(indPos, " ");
		}
	}
}
