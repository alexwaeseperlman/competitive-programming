#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	ull n; cin >> n;

	vector<int> digits;

	while (n) {
		digits.push_back(n%10);
		n /= 10;
	}

	sort(digits.begin(), digits.end());

	ull maxProd = 0;
	for (int mask = 1; mask < (1 << digits.size()); mask++) {
		ull a=0, b=0;
		int x = 1;
		for (int i = digits.size()-1; i >= 0; i--) {
			ull &target = (x & mask) ? a : b;
			x <<= 1;

			target = target * 10;
			target += digits[i];
		}

		maxProd = max(maxProd, a*b);
	}
	cout << maxProd << endl;
	
}
