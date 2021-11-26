#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define IOS 2129920
char _i[IOS], _; int _i0;
#define scan(x) for (x = _i[_i0++] & 15; (_ = _i[_i0++]) & 16; x = (x << 3) + (x << 1) + (_ & 15))
char _;
typedef unsigned int ui;

static inline const ui min(const ui x, const ui y) {
	return x<y?x:y;
}

ui t[200001];
ui N, M, l, r;

int main() {
    fread(_i, 1, IOS, stdin);
    t[0]=1000001;
	char q;
	scan(N); scan(M);
	for (ui i = 0; i < N; i++) scan(t[i+N]);
	for (ui i = N-1; i > 0; i--) {
		t[i] = min(t[i<<1|1], t[i<<1]);
	}
 
	for (ui i = 0; i < M; i++) {
		q = _i[_i0], _i0 += 2;
		scan(l); scan(r);
		if (q == 'M') {
			l += N;
			t[l] = r;
			for (l>>=1; l; l>>=1) {
				t[l] = min(t[l<<1], t[l<<1|1]);
			}
		}
		else {
			ui out = 10000001;
			for (l+=N, r+=N; l <= r; l>>=1,r>>=1) {
				out = min(out, t[l*(l&1)]);
				l+=l&1;
				out = min(out, t[r*(~r&1)]);
				r-=~r&1;
			}

			printf("%d\n", out);
		}
	}
}
