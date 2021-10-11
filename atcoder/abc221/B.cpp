#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	map<char, int> chars;
	string s, t; cin >> s >> t;

	if (s == t) {
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 0; i < s.size() - 1; i++) {
		swap(s[i], s[i+1]);
		if (s == t) {
			cout << "Yes" << endl;
			return 0;
		}
		swap(s[i], s[i+1]);
	}
	cout << "No" << endl;
}
