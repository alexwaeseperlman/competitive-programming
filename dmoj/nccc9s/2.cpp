#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N; cin >> N;
	vector<int> is;
	for (int i = 0; i < 2*N; i++) {
		char c; cin >> c;
		if (c == 'I') is.push_back(i);
	}
	ll swaps = 0;
	for (int i = 0; i < N; i++) {
		swaps += abs(is[i]-2*i);
	}
	cout << swaps << endl;
}
