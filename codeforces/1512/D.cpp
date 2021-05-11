#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr;
	arr.resize(n + 2);

	for (int i = 0; i < n + 2; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	// sum must be either last or second last
	
	long long sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}

	if (sum - arr[arr.size() - 1] == arr[arr.size() - 2] * 2) {
		for (int i = 0; i < arr.size() - 2; i++) cout << arr[i] << " ";
		cout << endl;
		return;
	}
	
	//cout << sum << " " << arr[n - 1] << endl;
	vector<bool> added;
	bool removed = false;
	added.resize(n + 2);
	for (int i = 0; i < arr.size()-1; i++) {
		if (sum - arr[i] == arr[arr.size() - 1] * 2 && !removed) {
			added[i] = false;
			removed = true;
			continue;
		}
		added[i] = true;
	}
	if (!removed) cout << "-1";
	else {
		for (int i = 0; i < added.size(); i++) {
			if (added[i]) cout << arr[i] << " ";
		}
	}
	cout << endl;

}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
