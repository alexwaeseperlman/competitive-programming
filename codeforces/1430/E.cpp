#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;

	int l = (n-1)/2, r = n/2;
	// stores the first and last positions of each character in the reversed string
	vector<pair<int, int>> pos(26, {numeric_limits<int>::max(), numeric_limits<int>::lowest()});

	int steps = 0;
	while (l >= 0) {
		steps += 

		pos[s[l]-'a'].first = l;
		pos[s[r]-'a'].second = r;
		l--;
		r++;
	}

}
