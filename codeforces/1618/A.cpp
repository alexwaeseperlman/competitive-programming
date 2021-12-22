#include <bits/stdc++.h>
using namespace std;

long long arr[7];
int main() {
	int t; cin >> t;

	while (t--) {
		for (int i = 0; i < 7; i++) cin >> arr[i];
		cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1] << endl;
	}
}
