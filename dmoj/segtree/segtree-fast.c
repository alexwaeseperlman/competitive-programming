#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

char _i[1 << 22], _; int _i0;
#define scan(x) for (x = _i[_i0++] & 15; (_ = _i[_i0++]) & 16; x = (x << 3) + (x << 1) + (_ & 15))
char _;
#define min(x, y) (((x)<(y))?(x):(y))
typedef unsigned int ui;

ui t[200001];
ui N, M, x, y;
void build() {
	for (ui i = N-1; i > 0; i--) {
		t[i] = min(t[i<<1|1], t[i<<1]);
	}
}

static inline void update(ui i, const ui x) {
	i += N;
	t[i] = x;
	for (i>>=1; i; i>>=1) {
		t[i] = min(t[i<<1], t[i<<1|1]);
	}
}

static inline const ui query(ui l, ui r) {
	int out = 10000001;
	for (l+=N, r+=N; l < r; l>>=1,r>>=1) {
		if (l&1) out = min(out, t[l]),l++;
		if (~r&1) out = min(out, t[r]),r--;
	}
	return min(t[l*(l==r)], out);
}

int main() {
    fread(_i, 1, 1 << 22, stdin);
    t[0]=1000001;
	char q;
	scan(N); scan(M);
	for (ui i = 0; i < N; i++) scan(t[i+N]);
	build();
 
	for (ui i = 0; i < M; i++) {
		q = _i[_i0], _i0 += 2;
		scan(x); scan(y);
		if (q == 'M') update(x, y);
		else printf("%d\n", query(x, y));
	}
}
