#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ull = unsigned long long;
 
vector<string> powsOfTwo;

void solve() {
	ull n; cin >> n;
	string s = to_string(n);

	ull m = 1000000;
	string x = "";
	for (string p : powsOfTwo) {
		int si = 0, same = 0;
		for (int i = 0; i < p.size(); i++) {
			while (si < s.size() && s[si] != p[i]) si++;
			if (si < s.size()) {
				same++;
				si++;
			}
		}
		m = min((ull)s.size() + p.size() - 2*same, m);
		//cout << "same: "<< same << " " << p << " " << m << endl;
	}
	cout << m << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull x = 1;
 
	int total = 0;
	while (x < 1000000000000000000) {
		string s = to_string(x);
		powsOfTwo.push_back(s);
		x *= 2;
		total++;
	}
 
	int t; cin >> t;
	while (t--) {
		solve();
	}
 
}
