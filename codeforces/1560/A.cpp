#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	ull k; cin >> k;
	ull n = 0;
	for (ull i = 0; i < k; i++) {
		n++;
		while ((n % 10) == 3 || (n % 3 == 0))  n++;
	}
	cout << n << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
