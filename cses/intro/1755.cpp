#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	vector<int> f(26);
	for (char c : s) f[c-'A']++;
	int odd = 0;
	for (int i : f) {
		odd += i&1;
	}
	if (odd > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	deque<char> out;
	for (int i = 0; i < 26; i++) {
		if (f[i]&1) {
			f[i]--;
			out.push_back(i+'A');
		}
	}
	for (int i = 0; i < 26; i++) {
		while (f[i] > 0) {
			f[i] -= 2;
			out.push_front(i+'A');
			out.push_back(i+'A');
		}
	}
	for (char c : out) cout << c;
	cout << endl;
}
