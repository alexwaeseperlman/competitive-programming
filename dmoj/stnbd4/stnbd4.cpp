#pragma GCC optimize "Ofast"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct query {
	ll l, r, i;
	ll block;
	const bool operator<(const query &rhs) const {
		return (block < rhs.block) || (block == rhs.block && r < rhs.r);
	}
};

ll A[100001], t[200001], N;
query Q[100001];

void add(ll i, ll x) {
	for (i+=N; i>0; i>>=1) t[i]+=x;
}

ll sum(ll l, ll r) {
	ll out = 0;
	for (l+=N,r+=N; l<r; l>>=1,r>>=1) {
		out += (l&1)*t[l];
		l+=l&1;
		out += (~r&1)*t[r];
		r-=~r&1;
	}

	return out+(l==r)*t[l];
}

ll above(ll i) {
	return sum(i+1, N-1);
}
ll below(ll i) {
	return sum(0, i-1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scan(N);

	vector<ll> c(N);
	for (ll i = 0; i < N; i++) scan(A[i]);
	copy(A, A + N, c.begin());
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	// coordinate compression
	for (ll i = 0; i < N; i++) {
		ll lb = 0, ub = N;
		while (lb < ub) {
			ll m = (lb+ub)/2;
			if (c[m] >= A[i]) ub = m;
			else if (c[m] < A[i]) lb = m+1;
		}

		A[i] = lb;
	}

	ll B = sqrt(N);
	ll q; scan(q);
	vector<ll> results(q);
	for (ll i = 0; i < q; i++) {
		scan(Q[i].l);scan(Q[i].r);
		Q[i].l--;
		Q[i].r--;
		Q[i].i = i;
		Q[i].block = Q[i].l/B;
	}
	sort(Q, Q + q);

	ll l = 0, r = 0;
	ll inversions = 0;

	int block = -1; 
	for (int i = 0; i < q; i++) {
		query q = Q[i];
		if (q.block != block) {
			fill(t, t + 2*N+1, 0);
			l = q.l, r = q.r;
			inversions = 0;
			for (ll i = l; i <= r; i++) {
				inversions += above(A[i]);
				add(A[i], 1);
			}
			block = q.block;
		}
		while (l < q.l) {
			inversions -= below(A[l]);
			add(A[l], -1);
			l++;
		}
		while (l > q.l) {
			l--;
			inversions += below(A[l]);
			add(A[l], 1);
		}
		while (r < q.r) {
			r++;
			inversions += above(A[r]);
			add(A[r], 1);
		}
		while (r > q.r) {
			inversions -= above(A[r]);
			add(A[r], -1);
			r--;
		}
		results[q.i] = inversions;
	}

	for (ll i : results) printf("%lld\n", i); 
}
