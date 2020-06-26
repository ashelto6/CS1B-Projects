// This program incorporates vectors
//4/22/2020
// Antonio S.-M.

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::vector;

int main() {
  
  double num;
  char op;
  vector<double> userVec;
  vector<double>::iterator found;

  cout << "enter operation [a/r/q] and number: ";
  cin >> op;

  while (op != 'q' && op != 'Q') {
    cin >> num;
    found = find(userVec.begin(), userVec.end(), num);

    if (op == 'a' || op == 'A') {
      if (found == userVec.end())
	userVec.push_back(num);
    }
    else if (op == 'r' || op == 'R') {
      if (found != userVec.end())
	userVec.erase(found);
    }
    cout << "your numbers: ";
    for (found = userVec.begin(); found != userVec.end(); ++found)
      cout << *found << " ";


    cout << "\nenter operation [a/r/q] and number: ";
    cin >> op;

  }
}
