#include <algorithm>
#include <iostream>

#define cube(x) (x*x*x)

using ll = long long;
using namespace std;

void solve() {
    ll x;
    cin >> x;

	ll lb = 0, ub = min(x, 2097152ll);

	// Binary search to find cube root of x
	while (ub - lb > 1) {
		ll b = (lb + ub) / 2;
		if (cube(b) > x) {
			ub = b;
		}
		else {
			lb = b;
			if (cube(b) == x) break;
		}
	}

    for (ll a = 1; cube(a) < x; a++) {
		while (cube(a) + cube(lb) > x) lb--;
		if (cube(a) + cube(lb) == x) {
			cout << "YES" << endl;
			return;
		}
    }
    cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
