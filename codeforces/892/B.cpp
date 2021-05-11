#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int L[n];

	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}

	int len = 0;
	int live = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (len <= 0) live++;
		len--;
		len = max(len, L[i]);
	}
	cout << live << endl;
}
