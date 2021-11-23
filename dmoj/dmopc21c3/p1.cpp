#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int N; cin >> N;
	vector<ll> arr(N), pfix(N), a(N);
	for (int i = 1; i < N; i++) {
		ll ans;
		cout << "? " << 1 << " " << i+1 << endl;
		cout.flush();
		cin >> ans;
		arr[i] = ans;
	}

	ll last;
	cout << "? " << N << " " << 1 << endl;
	cout.flush();
	cin >> last;
	last = (last/2);
	a[N-1] = last;
	
	ll pf = arr[N-1] + last;
	pfix[N-1] = pf;

	for (int i = N-2; i >= 1; i--) {
		pf = (arr[i] + pf)/2;
		pfix[i] = pf;
		a[i] = pfix[i] - arr[i];
	}

	a[0] = pfix[1];
	cout << "! ";
	for (ll i : a) cout << i << " ";
	cout << endl;
}
