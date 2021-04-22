#include <cmath>
#include <iostream>

inline int min(int a, int b) {
	return a * (a < b) + b * (b <= a);
}

using namespace std;

int paths[100001];
int h[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	paths[0] = 0;
	paths[1] = abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		paths[i] = min(paths[i - 2] + abs(h[i - 2] - h[i]), paths[i - 1] + abs(h[i - 1] - h[i]));
	}

	cout << paths[n - 1] << endl;
}
