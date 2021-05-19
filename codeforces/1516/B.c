#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int solve() {
	ll n; scanf("%lld", &n);

	ll arr[n], prefix[n], suffix[n];

	for (ll i = 0; i < n; i++) scanf("%lld", arr + i);
	prefix[0] = arr[0];
	suffix[n-1] = arr[n-1];
	for (ll i = 1; i < n; i++) {
		prefix[i] = prefix[i-1] ^ arr[i];
		suffix[n-i-1] = suffix[n-i] ^ arr[n-i-1];
	}

	for (ll i = -1; i < n; i++) {
		ll before = i >= 0 ? prefix[i] : 0, after = i < n-1 ? suffix[i+1] : 0;
		if (before == after) return 1;
	}

	for (ll i = -1; i < n; i++) {
		for  (ll j = i; j < n; j++) {
			ll left = i >= 0 ? prefix[i] : 0, right = j < n-1 ? suffix[j+1] : 0;
			if (i != j) {
				ll middle = (suffix[0] ^ left) ^ right;
				if (left == right && left == middle) return 1;
			}
			else if (left == right) return 1;

		}
	}

	return 0;
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) {
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
}
