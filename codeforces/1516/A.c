#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

void solve() {
	ll n, k;
	scanf("%lld %lld", &n, &k);

	ll arr[n];

	for (ll i = 0; i < n; i++) scanf("%lld", &arr[i]);

	ll start = 0;
	ll end = n-1;
	for (ll i = 0; i < k; i++) {
		while (arr[start] <= 0 && start < end) start++;

		if (arr[start] == 0) {
			arr[end]--;
			arr[start]++;
		}
		else {
			arr[start]--;
			arr[end]++;
		}
	}

	for (ll i = 0; i < n; i++) printf("%lld ", arr[i]);
	printf("\n");
}

int main() {
	ll n; scanf("%lld", &n);
	
	while (n--) solve();
}
