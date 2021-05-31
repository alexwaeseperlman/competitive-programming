#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

string minMerge(string &a, string &b) {
	string out = "";

	ull ai = 0, bi = 0;

	while (ai < a.size() || bi < b.size()) {
		if (ai < a.size()) {
			out += a[ai];
			if (a[ai] == b[bi]) {
				bi++;
			}
			ai++;
		}
		else {
			out += b[bi];
			bi++;
		}
		
	}
	return out;
}

void solve() {
	ull n; cin >> n;
	string a, b, c; cin >> a >> b >> c;

	string ab = minMerge(a,b), ac = minMerge(a,c), bc = minMerge(b,c);

	string *min = &ab;
	if (ac.size() < ab.size()) min = &ac;
	if (bc.size() < min->size()) min = &bc;
	cout << *min << endl;
}

int main() {
	ull t; cin >> t;
	while (t--) solve();
}
