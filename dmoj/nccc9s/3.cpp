#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;

	char p = 'U';
	int moves = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U' && p == 'U') {
			moves++;
		}
		p = s[i];
	}
	cout << moves << endl;

}
