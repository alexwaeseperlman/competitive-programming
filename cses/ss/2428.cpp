#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int compress(vector<int> &arr) {
	map<int, int> ids;
	for (int i = 0; i < arr.size(); i++) {
		if (!ids[arr[i]]) ids[arr[i]] = ids.size();
		arr[i] = ids[arr[i]];
	}
	return arr.size();
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int sizes = compress(a);
	
	vector<int> freqs(sizes);
	ll count = 0, j = 0;
	ll total = 0;
	for (ll i = 0; i < n; i++) {
		freqs[a[i]]++;
		if (freqs[a[i]] == 1) count++;
		while (count > k) {
			freqs[a[j]]--;
			if (freqs[a[j]] == 0) count--;
			j++;
		}
		total += (i-j+1);
	}
	cout << total << endl;
}
