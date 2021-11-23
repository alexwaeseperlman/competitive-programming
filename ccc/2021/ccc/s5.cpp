#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a*(b/gcd(a,b));
}

struct segtree {
	ll N;
	vector<ll> t, d;
	int height;
	segtree(ll N): N(N) {
		d = vector<ll>(2*N+1, 1);
		t = vector<ll>(2*N+1, 1);
		height = sizeof(int)*8 - __builtin_clz(N);
	}
	
	int merge() {
		return 0;
	}
	int merge(int x, int y) {
		return gcd(x, y);
	}
	int join(int x, int y) {
		return lcm(x, y);
	}

	void push(int x) {
		if (d[x] == 1) return;
		t[x] = join(t[x], d[x]);
		if ((x<<1) <= 2*N) d[x<<1] = join(d[x], d[x<<1]);
		if ((x<<1|1) <= 2*N) d[x<<1|1] = join(d[x], d[x<<1|1]);
		d[x] = 1;
	}

	void fall(int x) {
		int m = 0;
		while (x>>m) m++;
		for (int i = m; i >= 0; i--) {
			if (x>>i) push(x>>i);
		}
	}

	void update(int l, int r, int x) {
		l += N;
		r += N;
		while (l <= r) {
			if (l&1) {
				d[l] = join(d[l], x);
				l++;
			}
			if (~r&1) {
				d[r] = join(d[r], x);
				r--;
			}

			l >>= 1;
			r >>= 1;
		}
	}

	int query(int l, int r) {
		l += N;
		r += N;
		fall(l);
		fall(r);

		ll out = merge();
		while (l <= r) {
			if (l&1) {
				out = merge(t[l++], out);
				fall(l);
			}
			if (~r&1) {
				out = merge(t[r--], out);
				fall(r);
			}
			l>>=1;
			r>>=1;
		}
		return out;
	}

};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n, m; scan(n); scan(m);

	segtree s(n);
	vector<array<ll, 3>> queries;
	for (int i = 0; i < m; i++) {
		ll x, y, z;
		scan(x); scan(y); scan(z);
		x--;
		y--;
		queries.push_back(array<ll, 3>({x, y, z}));
		s.update(x, y, z);
	}
	bool possible = true;
	for (auto i : queries) {
		if (s.query(i[0], i[1]) != i[2]) {
			possible = false;
			break;
		}
	}
	if (possible) {
		for (ll i = 0; i < n; i++) {
			printf("%d ", s.query(i, i));
		}
		printf("\n");
	}
	else printf("Impossible\n");
}
