#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	ll a, b; cin >> a >> b;
	if ((a+b)%3) goto NO;
	if (abs(a-b) > min(a,b)) goto NO;
	cout << "YES" << endl;
	return;
NO: cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
