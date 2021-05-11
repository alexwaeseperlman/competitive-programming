#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	bool solvable = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[s.size() - i - 1] != 'a') {
			solvable = true;
			s.insert(i, "a");
			break;
		}
	}

	if (!solvable) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
