#include <stdio.h>
#include <stdlib.h>

#define better(x, y, op) ((x) * ((x) op (y)) + (y) * !((x) op (y)))

int main() {
	int N, M, Q;

	scanf("%d %d %d", &N, &M, &Q);

	int* prefixArray = calloc(N * M + 2, sizeof(int));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			prefixArray[(i + 1) * (j + 1)]++;
			prefixArray[i * M + j * (N - i) + 2]--;
		}
	}

	int acc = 0;
	for (int i = 0; i < N * M + 1; i++) {
		acc += prefixArray[i];
		prefixArray[i] = acc;
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d", &acc);
		printf("%d\n", prefixArray[acc]);
	}
	
cleanup:
	free(prefixArray);
	return 0;
}
