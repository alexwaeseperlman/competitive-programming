#include <cmath>
#include <cstdint>
#include <iostream>
#include <algorithm>

using namespace std;

int h[100001];
int paths[100001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = 1; i < n; i++) {
		int min = INT32_MAX;
		for (int j = i - 1; j >= i - k && j >= 0; --j) {
			int c = paths[j] + abs(h[i] - h[j]);
			if (c < min) min = c;
		}
		paths[i] = min;
	}

	cout << paths[n - 1] << endl;

}
