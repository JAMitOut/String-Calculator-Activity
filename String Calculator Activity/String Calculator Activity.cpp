#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

int string_calculator(const string& str) {
	if (str.empty()) return 0;

	string normalized = str;
	for (char& c : normalized) {
		if (c == ';') c = ',';
	}

	int sum = 0;
	string token;
	stringstream ss2(normalized);

	while (getline(ss2, token, ',')) {
		if (!token.empty()) {
			sum += stoi(token);
		}
	}

	return sum;
}

int main() {
	assert(string_calculator("") == 0);
	assert(string_calculator("0") == 0);
	assert(string_calculator("1") == 1);
	assert(string_calculator("1,2") == 3);
	assert(string_calculator("4,5,6") == 15);
	assert(string_calculator("1;2;3") == 6);
	assert(string_calculator("10,20;30") == 60);

	cout << "All Tests Passed!";
	return 0;
}