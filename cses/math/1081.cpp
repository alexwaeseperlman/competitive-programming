#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

int counts[1000001];

int main() {
	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		for (int i = 1; i*i <= x; i++) {
			if (x%i == 0) {
				counts[i]++;
				if (x/i != i) counts[x/i]++;
			}
		}
	}
	int g = 1000001;
	while (counts[--g] < 2);

	cout << g << endl;
}
