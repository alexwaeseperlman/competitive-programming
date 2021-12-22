#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	vector<int> psum(N+1);
	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i-1] + (s[i-1] == 'H');
	}

	ll out = 0, total = 0;
	for (ll i = 1; i <= N-2; i++) {
		int lb = i, ub = N+1;
		while (lb < ub) {
			int m = (lb + ub)/2;
			int len = m-i+1, type = psum[m] - psum[i-1];
			if (type < 2 || len-type < 2) lb = m+1;
			else ub = m;
		}
		ll start = lb;
		lb = i, ub = N+1;
		bool a = s[i-1] != 'H';
		while (lb < ub) {
			int m = (lb + ub)/2;
			int len = m-i+1, type = psum[m] - psum[i-1];
			if ((a && type == 0) || (!a && len-type == 0)) lb = m+1;
			else ub = m;
		}
		lb--;
		ll end = lb;
		ll count = N-start+1;
		if (end >= i+2) count += end-i-1;
		out += count;
		total += N - 1 - i;
	}
	cout << total - out << endl;
}
