//bruteforce
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll base = 3931177;

ll fromState(vector<bool> &s) {
	ll x = 0, p = 1;
	for (int i = 0; i < s.size(); i++) {
		x = (x+s[i] * p)%base;
		p = (p<<1)%base;
	}
	return x;
}

int main() {
	ll n, t; cin >> n >> t;

	vector<bool> state(n), nst(n);
	// solution for n < 15
	vector<int> order(base);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		state[i] = c == '1';
	}

	ll i = 0;
	ll start = 0, end = 0;
	ll target = 0;

	while (t) {
		t--;
		nst = state;
		for (int j = 0; j < n; j++) {
			if ((int)state[(n+j-1)%n] + (int)state[(n+j+1)%n] == 1) nst[j] = 1;
			else nst[j] = 0;
		}
		state = nst;
		ll s = fromState(state);
		if (start && s == target) {
			end = i;
			t = t % (end-start);
			start = 0;
		}
		else if (!start && !target && order[s]) {
			start = i;
			target = s;
		}
		order[s] = ++i;
	}

	
	for (int i : state) cout << i;
	cout << endl;


}
