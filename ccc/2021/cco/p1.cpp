#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


pair<ll, vector<ll>> minv(vector<ll> &a, vector<ll> &b) {
	vector<ll> out;
	ll inv = 0;
	ll ai = 0, bi = 0;
	while (ai < a.size() && bi < b.size()) {
		if (b[bi] < a[ai]) {
			out.push_back(b[bi]);
			bi++;
		}
		else {
			out.push_back(a[ai]);
			ai++;
			inv += bi;
		}
	}
	while (bi < b.size()) {
		out.push_back(b[bi]);
		bi++;
	}
	while (ai < a.size()) {
		out.push_back(a[ai]);
		ai++;
		inv += bi;
	}
	return {inv, out};
}

ll inversions(vector<ll> &arr) {
	if (arr.size() <= 1) return 0;
	vector<ll> a(arr.size()/2), b((arr.size()+1)/2);
	copy(arr.begin(), arr.begin()+arr.size()/2, a.begin());
	copy(arr.begin()+arr.size()/2, arr.end(), b.begin());
	ll inv = inversions(a) + inversions(b);
	auto m = minv(a, b);
	arr = m.second;
	inv += m.first;
	return inv;
}

ll invCount(vector<ll> &small, vector<ll> &big) {
	if (small.size() > big.size()) return small.size() * big.size() - invCount(big, small);
	ll count = 0;
	ll si = 0, bi = 0;

	while (si < small.size()) {
		ll lb = bi, ub = big.size();
		while (lb < ub) {
			ll m = lb+(ub-lb)/2;
			if (big[m] >= small[si]) ub = m;
			else lb = m+1;
		}
		bi = lb;
		count += bi;
		si++;
	}

	return count;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n, k, q;scan(n); scan(k); scan(q);
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) scan(a[i]);

	vector<vector<ll>> idxs(k+1);
	for (ll i = 0; i < n; i++) {
		idxs[a[i]].push_back(i);
	}

	vector<map<ll, ll>> swaps(k+1);
	vector<ll> permutation(k+1);
	for (ll i = 0; i <= k; i++) permutation[i] = i;

	ll inv = inversions(a);

	auto getSwaps = [&](ll a, ll b) {
		ll x = min(a, b), y = max(a, b);
		ll invs = 0;
		if (min(idxs[x].size(), idxs[y].size()) > 100) {
			if (!swaps[x].count(y)) swaps[x][y] = invCount(idxs[x], idxs[y]);
			invs = swaps[x][y];
		}
		else invs = invCount(idxs[x], idxs[y]);
		ll out = 2*invs - idxs[a].size() * idxs[b].size();
		if (a < b) return out;
		else return -out;
	};

	for (ll i = 0; i < q; i++) {
		ll j; scan(j);
		swap(permutation[j], permutation[j+1]);
		inv += getSwaps(permutation[j], permutation[j+1]);
		printf("%lld\n", inv);
	}
}
