#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using dd = long double;

const dd eps = 0.00001;
const ull N = 1000;

bool aboveN(ull losses, dd n=1000000000.0) {
	dd lb = 0.0, ub = 1.0;
	dd high, old;
	ull i = 0;

	auto getHigh = [&](dd x) {
		dd out = 1.0;
		for (ull i = 0; i < N; i++) {
			if (i >= losses) out *= (1.0-x);
			else out *= (1.0+2*x);
		}
        return out;
	};

	do {
		i++;
		dd x = (lb + ub)/2.0;
		high = getHigh(x);
        old = x;
		dd diff = (getHigh(x + eps) - getHigh(x));
        cout << losses << ": " << x << " " << high << endl;
		
		if (diff > 0) lb = x;
		else ub = x;
	} while (high <= n && i < 100);
    if (high >= n) {
        cout << setprecision(15) << old << " " << high << endl;
    }
	return high >= n;
}

int main() {
	ull lb = 0, ub = N-1;
	
	for (int i = 0; i < 1000; i++) {
		if (aboveN(i)) {
			cout << i << endl;
			break;
		}
	}
}