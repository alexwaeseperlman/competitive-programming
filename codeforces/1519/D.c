#include <stdlib.h>
#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

typedef unsigned long long ll;

ll a[5010];
ll b[5010];
ll preproductSums[5010];
ll postproductSums[5010];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%llu", a + i);
	for (int i = 0; i < n; i++) scanf("%llu", b + i);

	ll max = 0;
	for (int i = 0; i < n; i++) {
		max += a[i] * b[i];
		preproductSums[i + 1] = max;
	}
	for (int i = n - 1; i >= 0; i--) {
		postproductSums[i] = a[i] * b[i];
		if (i < n - 1) postproductSums[i] += postproductSums[i + 1];
	}
	
	for (int i = 0; i < n; i++) {
		ll reversedSum = a[i] * b[i];
		for (int j = 1; j <= min(i, n - i - 1); j++) {
			reversedSum += a[i - j] * b[i + j] + a[i + j] * b[i - j];;
			ll sum = preproductSums[i - j] + postproductSums[i + j + 1] + reversedSum;
			if (sum > max) {
				max = sum;
			}
		}
	}

	for (int i = 0; i < n-1; i++) {
		ll reversedSum = 0;
		for (int j = 0; j <= min(i, n - i - 1); j++) {
			reversedSum += a[i - j] * b[i + j + 1] + a[i + j + 1] * b[i - j];;
			ll sum = preproductSums[i - j] + postproductSums[i + j + 2] + reversedSum;
			if (sum > max) {
				max = sum;
			}
		}
	}
	printf("%llu\n", max);
}
