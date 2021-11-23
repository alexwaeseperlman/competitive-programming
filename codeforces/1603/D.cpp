#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull gcd(ull x, ull y) {
	if (y > x) return gcd(y, x);
	if (y == 0) return x;
	return gcd(x%y, y);
}

ull solve(ull x, ull y) {
		//x, y = [int(i) for i in input().split(' ')]
    //if y % x == 0: print(x)
    //else: print(y*x+y)
	//
	if (y % x == 0) return x;
	else if (x > y) {
		return y*x+y;
	}
	else {
		return y*x+x;
	}


}

int main() {
	int t; cin >> t;

	for (ull i = 1000; i < 100000; i+=2) {
		for (ull j = i; j < 10000; j+=2) {
			if (solve(i, j) % i != j % solve(i, j)) cout << i << " " << j << " " << solve(i, j)<< endl;
		}

	}
	while (t--) {
		ull x, y; cin >> x >> y;
		cout << solve(x, y) << endl;
	}


}
