#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;

template<typename T>
bool all(vector<T> &a, T v) {
	for (T x : a) if (x != v) return false;
	return true;
}

void solve() {
	ull n; cin >> n;

	ull ones = 0, zeros = 0;
	vector<bool> arr(n, false);

	for (ll i = 0; i < n; i++) {
		char k; cin >> k;
		arr[i] = (k == '1');
		if (arr[i]) ones++;
		else zeros++;
	}

	if (zeros % 2 == 1 && zeros > 1) {
		cout << "ALICE" << endl;
	}
	else cout << "BOB" << endl;

/*	ll scores[2] = {0, 0};
	bool a = 1, reversed = false;

	while (!all(arr, true)) {
		// Find an unequal pair
		ll pairI = -1, zeroI = -1;
		ull pairs = 0;
		for (ull i = 0; i < n; i++) {
			if (arr[i] == 0) zeroI = i;
			if (arr[i] != arr[arr.size() - 1 - i] && arr[i] == 0 || (i == arr.size() - 1 - i && arr[i] == 0)) {
				pairs++;
				pairI = i;
			}
		}

		if (pairI == -1 || (pairs == 1 && zeros > 1) || reversed) {
			//cout << (a ? "alice" : "bob") << " " << "set" << endl;
			pairI = pairI == -1 ? zeroI : pairI;
			scores[a]++;

			arr[pairI] = 1;
			reversed = false;
			zeros--;
			ones++;
		}
		else {
			//cout << (a ? "alice" : "bob") << " " << "reverse" << endl;
			reversed = true;
		}
		a = !a;
	}

	if (arr.size() == 1) {
		cout << "BOB" << endl;
		return;
	}

	if (scores[0] == scores[1]) cout << "DRAW" << endl;
	else if (scores[0] > scores[1]) cout << "ALICE" << endl;
	else cout << "BOB" << endl;
	*/

}

int main() {
	ull t; cin >> t;
	while (t--) solve();
}
