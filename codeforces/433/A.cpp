#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> w(n); for (int i = 0; i < n; i++) cin >> w[i];
	int ones = 0, twos = 0;
	for (int i : w) {
		if (i == 100) ones++;
		else twos++;
	}
	if (ones&1 || twos&1 && ones < 2) {
		cout << "NO" << endl;
	}
	else cout <<"YES" << endl;

}
