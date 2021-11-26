#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

	int count = 1, mcount = 0;
	for (int i = 1; i < s.size(); i++) {
		if (count > mcount) mcount = count;
		if (s[i] != s[i-1]) count = 0;
		count++;
	}
	cout << max(count, mcount) << endl;
}
