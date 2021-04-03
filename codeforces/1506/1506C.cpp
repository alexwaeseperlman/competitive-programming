#include <bits/stdc++.h>

using namespace std;

int solve() {
	string a, b;
	cin >> a >> b;

	string &smaller = a.size() < b.size() ? a : b;
	string &larger = a.size() < b.size() ? b : a;
	int largerSize = larger.size();
	
	// Pad the start of the larger string so that it lines up with the end of the smaller string
	// For example with abcdefg and pcdf:
	// ___abcdefg___
	// pcdf
	// ___abcdefg___
	//          pcdf
	for (int i = 0; i < smaller.size() - 1; i++) {
		larger = "_" + larger + "_";
	}

	int minOperations = 10e7;
	// Shift the starting point for comparison
	// ___abcdefg___
	//  pcdf
	// ___abcdefg___
	//   pcdf
	for (int i = 0; i < larger.size(); i++) {
		// Find the length of the longest equal set of connected characters
		// For example in bcde and pcdf
		// bcde
		// pcdf
		// ^    unequal
		// bcde
		// pcdf
		//  ^   equal
		// bcde
		// pcdf
		//   ^  equal
		// bcde
		// pcdf
		//    ^ unequal
		
		// Longest Equal Substring Length
		int lesl = 0;
		int length = 0;

		for (int j = 0; j < smaller.size(); j++) {
			if (smaller[j] == larger[j + i]) {
				length++;
			}
			else {
				length = 0;
			}
			if (length > lesl) lesl = length;
		}
		int operations = smaller.size() - lesl + largerSize - lesl;
		if (operations < minOperations) minOperations = operations;
	}
	return minOperations;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << solve() << endl;
	}
}
