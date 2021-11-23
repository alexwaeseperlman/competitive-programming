#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b; cin >> a >> b;
	vector<int> counts(26);
	int wcs = 0;
	for (char c : a) {
		counts[c-'a']++;
	}
	for (char c : b) {
		if (c == '*') wcs++;
		else counts[c-'a']--;
	}

	bool anagram = true;
	for (int i = 0; i < 26; i++) {
		if (counts[i] < 0) {
			anagram = false;
			break;
		}
		wcs -= counts[i];
	}
	if (anagram && wcs == 0) cout << "A" << endl;
	else cout << "N" << endl;
	
}
