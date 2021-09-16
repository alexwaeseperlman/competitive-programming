#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll ax, ay, bx, by, fx, fy; cin >> ax >> ay >> bx >> by >> fx >> fy;

	bool blocking = (ay == by && fy == ay && min(ax, bx) < fx && max(ax, bx) > fx)
		        ||  (ax == bx && fx == ax && min(ay, by) < fy && max(ay, by) > fy);

	cout << (blocking * 2 + (abs(ax - bx) + abs(ay - by))) << endl;

}

int main() {
	ll t; cin >> t;

	while (t--) solve();
}
