#include <bits/stdc++.h>
using namespace std;

int divs[1000001];

int main() {
	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			divs[j]++;
		}
	}
	int n; cin >> n;

	while (n--) {
		int x; cin >> x;
		cout << divs[x] << endl;
	}
}
