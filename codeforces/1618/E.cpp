#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll b[40001], a[40001];
 
void solve() {
	ll n; cin >> n;
 
	for (ll i = 0; i < n; i++) cin >> b[i];
	ll sumA = 0;
	for (ll i = 0; i < n; i++) sumA += b[i];
	if ((sumA*2) % (n*(n+1)) != 0) {
		cout << "NO" << endl;
		return;
	}
	sumA /= (n*(n+1))/2;
 
	for (ll i = 0; i < n; i++) {
		a[i] = (b[i] - b[(n+i-1)%n] - sumA) / (-n);
		if (a[i] <= 0 || a[i] > 1000000000 || (b[i] - b[(n+i-1)%n]-sumA)%n != 0) {
			cout << "NO" << endl;
			return;
		}
	}
 
	cout << "YES" << endl;
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
 
int main() {
	int t; cin >> t;
	while (t--) solve();
}
