#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int l; string s; cin >> l >> s;

	vector<int> as;
	as.push_back(0);

	int a = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') a++;
		as.push_back(a);
	}

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < i; j++) {
			int len = i - j;
			int t = as[i] - as[j];
			if (len == t * 2) {
				cout << j + 1 << " " << i << endl;
				return;
			}
		}
	}
	cout << "-1 -1" << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
	
}
