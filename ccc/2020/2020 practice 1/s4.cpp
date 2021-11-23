#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	vector<ll> factors;
	for (ll i = 1; i < N; i++) {
		if (N%i == 0) factors.push_back(i);
	}

	auto moves = [&](ll k) -> ll {
		ll size = N/k;
		ll offsets[k][size];

		for (int i = 0; i < N; i++) {
			offsets[i%k][i/k] = a[i];
		}
		ll total = 0;
		vector<ll> psum(size+1);
		for (int i = 0; i < k; i++) {
			sort(offsets[i], offsets[i] + size);
			partial_sum(offsets[i], offsets[i] + size, psum.begin()+1);
			ll lb = offsets[i][0], ub = offsets[i][size-1]+1;

			ll last;
			while (lb < ub) {
				ll first = 0, second = 0;
				for (ll m : {(2*lb+ub)/3, (lb+2*ub)/3}) {
					// find the location in the array
					ll firstIdx = lower_bound(offsets[i], offsets[i]+size, m) - offsets[i];
					ll before = psum[firstIdx], after = psum[size] - psum[firstIdx];

					ll steps = firstIdx*m - before + after - (size-firstIdx)*m;
					if (first) second = steps;
					else first = steps;
				}
				if (first > second) {
					lb = 1+(2*lb+ub)/3;
					last = second;
				}
				else if (first <= second) {
					ub = (lb+2*ub)/3;
					last = first;
				}
			}
			total += last;
		}

		return total;
	};

	ll m = numeric_limits<ll>::max();
	for (ll i : factors) {
		ll moved = moves(i);
		m = min(moved, m);
	}
	if (N == 1) cout << 0 << endl;
	else cout << m << endl;

}
