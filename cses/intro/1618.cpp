#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll total = 0;
	ll m = 5;
	ll n; cin >> n;
	while (m <= n) {
		total += n/m;
		m *= 5;
	}
	cout << total << endl;
}
