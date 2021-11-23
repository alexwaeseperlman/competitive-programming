#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> primes;
bitset<100000> notPrime;

ull gcd(ull a, ull b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a%b);
}

ull lcm(ull a, ull b) {
	return (a*b)/gcd(a, b);
}

void solve() {
	int n; cin >> n;
	vector<ull> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool solution = true;
	ull p = 1;
	for (ull i = 0; i < n && p < 1000000000ull; i++) {
		p = lcm(p, i + 2);
		if (a[i] % p == 0) {
			solution = false;
			break;
		}
	}

	if (!solution) cout << "NO" << endl;
	else cout << "YES" << endl;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < notPrime.size(); i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (int j = 2*i; j < notPrime.size(); j+=i) {
				notPrime[j] = true;
			}
		}
	}

	int t; cin >> t;
	while (t--) solve();

}

