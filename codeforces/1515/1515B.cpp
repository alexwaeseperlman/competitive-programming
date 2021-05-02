#include <iostream>

using namespace std;
int isqrt(int n) {
	if (n == 1) return 1;
	int lb = 0, ub = n;
	while (ub - lb > 1) {
		int s = (lb + ub) / 2;
		if (s * s == n) return s;
		else if (n > s * s) lb = s;
		else if (n < s * s) ub = s;
	}
	return lb;
}

bool psquare(int n) {
	int s = isqrt(n);
	return s * s == n;
}


int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if ((n % 2 == 0  && psquare(n / 2)) || (n % 4 == 0 && psquare(n / 4))) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
