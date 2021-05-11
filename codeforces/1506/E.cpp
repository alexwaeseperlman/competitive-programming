#include <vector>
#include <iostream>
#include <set>

using namespace std;
int minimal[200001], maximal[200001];

void solve() {
	int n;
	cin >> n;

	set<int> order;
	for (int i = 1; i <= n; i++) {
	 order.emplace(i);
	}

	int high = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		
		if (k > high) {
			minimal[i] = k;
			maximal[i] = k;
			order.erase(k);
		}
		else {
			minimal[i] = -1;
			maximal[i] = -1;
		}
		high = k;
	}

	set<int> high_set = order;
	high = 0;
	auto minPtr = order.begin();
	auto maxPtr = high_set.begin();

	for (int i = 0; i < n; i++) {
		if (minimal[i] > high) {
			high = minimal[i];
		}
		else {
			maxPtr = high_set.upper_bound(high);
			maxPtr = prev(maxPtr);
			minimal[i] = *minPtr;
			minPtr = next(minPtr);
			maximal[i] = *maxPtr;
			high_set.erase(*maxPtr);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << minimal[i] << " ";
	}
	cout << endl;
	for (int i= 0; i < n; i++) {
		cout << maximal[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
