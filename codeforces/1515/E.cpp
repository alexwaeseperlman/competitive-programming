#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n, M, pow2[403]; 
 
ll ans[403][403];
 
void add(ll &a, ll b) {
	a = (a+b);
	if (a >= M) a -= M;
}
void mul(ll &a, ll b) {
	a = (a*b)%M;
}
 
const ll mc = 1001;
ll factorial[mc], choose[mc][mc];
int main() {
	cin >> n >> M;
	factorial[0] = 1;
 
	for (ll i = 0; i <= n; i++) {
		factorial[i] = factorial[i-1];
		mul(factorial[i], i);
		
		for (ll j = 0; j <= i; j++) {
			if (i == 0 || j == 0) choose[i][j] = 1;
			else {
				add(choose[i][j], choose[i-1][j]);
				add(choose[i][j], choose[i-1][j-1]);
			}
		}
	}
 
	pow2[0] = 1;
	for (int i = 1; i < n; i++) {
		pow2[i] = pow2[i-1];
		add(pow2[i], pow2[i]);
	}
 
	
	for (int i = 0; i <= n; i++) {
		ans[i][i] = pow2[i-1];
		for (int adding = 1; adding <= n-i; adding++) {
			for (int used = 0; used <= i; used++) {
				ll steps = pow2[adding-1];
				mul(steps, ans[i][used]);
				mul(steps, choose[adding+used][adding]);
				add(ans[i+adding+1][adding+used], steps);
			}
		}
	}
	ll total = 0;
	for (int i = 0; i <= n; i++) {
		add(total, ans[n][i]);
	}
	cout << total << endl;
}
