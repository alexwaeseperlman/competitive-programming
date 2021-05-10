#include <stdlib.h>
#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

typedef unsigned long long ll;

ll a[5001];
ll b[5001];
ll pps[5001];
ll aps[5001];
int main() { int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%llu", a + i);
	for (int i = 0; i < n; i++) scanf("%llu", b + i);

	ll max = 0;
	for (int i = 0; i < n; i++) {
		max += a[i] * b[i];
		pps[i + 1] = max;
	}
	for (int i = n - 1; i >= 0; i--) {
		aps[i] = a[i] * b[i];
		if (i < n - 1) aps[i] += aps[i + 1];
	}
	
	for (int s = 0; s <= 1; s++) {
		for (int i = 0; i < n - s; i++) {
			ll rs = (a[i] * b[i])*(1-s);
			for (int j = 1-s; j <= min(i, n - i - 1); j++) {
				rs += a[i - j] * b[i + j + s] + a[i + j + s] * b[i - j];;
				ll sum = pps[i - j] + aps[i + j + 1 + s] + rs;
				if (sum > max) {
					max = sum;
				}
			}
		}
	}
	printf("%llu\n", max);
}
