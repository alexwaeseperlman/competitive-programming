#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c; cin >> a >> b >> c;

	cout << max(0, 1+max(c,b)-a) << " " << max(0, 1+max(a,c)-b) << " " << max(0, 1+max(a,b)-c) << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
