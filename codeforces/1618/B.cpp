#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<char> arr;
	string s; cin >> s;
	bool added = false;
	for (int i = 1; i < n-2; i++) {
		arr.push_back(s[0]);
		string prev = s;
		cin >> s;
		if (prev[1] != s[0]) {
			added = true;
			arr.push_back(prev[1]);
		}
	}
	arr.push_back(s[0]);
	arr.push_back(s[1]);
	if (!added) arr.push_back('a');
	for (char c: arr) cout << c;
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
