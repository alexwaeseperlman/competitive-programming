// Counting sort
#include <stdio.h>
#include <stdlib.h>

int bins[32001];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);

		bins[k]++;
	}

	for (int i = 0; i < 32001; i++) while (bins[i]--) {
		printf("%d\n", i);
	}
}
