#include <bits/stdc++.h>
using namespace std;
using ull = long long;

void solve() {
	ull k; cin >> k;

	ull s = sqrt(k)+1;
	if (k == (s-1)*(s-1)) s--;
	ull ud = k-(s-1)*(s-1)-1, d = s*s-k;

	if (ud < s) {
		cout << ud+1 << " " << s << endl;
	}
	else {
		cout << s << " " << d+1 << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
