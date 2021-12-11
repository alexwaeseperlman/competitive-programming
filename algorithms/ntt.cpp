//#pragma GCC optimize "trapv"
#pragma GCC optimize "O3,fast-math"
#pragma GCC target "avx2"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using big = __int128;

ostream& operator<<(ostream &rhs, __int128 x) {
	return rhs << (long long)x;
}

big pow(big n, big p, big b) {
	big out = 1, x = n;
	for (ll i = 1; i <= p; i <<= 1) {
		if (p&i) out = (out*x)%b;
		x = (x*x)%b;
	}

	return out;
}

struct fft_prime {
	char s, p, gen;
};
ll buffer[2500000];
big primitiveRoots[100], pinv[100];
void fft(vector<ll> &x, fft_prime p, bool inv=false, int start=0, int step=1) {
	ll size = (x.size()-start+step-1)/step;
	ll bits = 64 - __builtin_clzll(size);
	if (1ll<<(bits-1) == size) bits--;
	ll n = 1ll<<bits;

	if (n > 2) {
		fft(x, p, inv, start, step*2); 
		fft(x, p, inv, start+step, step*2);
	}

	big prime_base = (((big)p.s)<<p.p)+1ll;
	big prim = primitiveRoots[bits], w=1;
	if (!inv) {
		prim = pinv[bits];
	}

	big half = (prime_base+1)>>1;

	for (int i = 0; 2*i < n; i++) {
		ll l = x[2*i*step + start], r = x[(2*i+1)*step + start];
		ll wr = (w*r)%prime_base;
		buffer[i*step + start] = l + wr;
		buffer[((n>>1)+i)*step + start] = l - wr;

		w = (w * prim)%prime_base;
	}
	for (int i = 0; 2*i < n; i++) {
		ll a = i*step + start, b = ((n>>1)+i)*step + start;
		x[a] = buffer[a];
		x[b] = buffer[b];
		if (x[a] >= prime_base) x[a] -= prime_base;
		if (x[b] < 0) x[b] += prime_base;

		if (inv) {
			if ((x[a]&1)==0) x[a]>>=1;
			else x[a] = ((big)x[a]*half)%prime_base;
			if ((x[b]&1)==0) x[b]>>=1;
			else x[b] = ((big)x[b]*half)%prime_base;
		}
	}
}

void ifft(vector<ll> &x, fft_prime p) {
	fft(x, p, true);
}

void poly_mul(vector<ll> &x, vector<ll> &y, fft_prime p) {
	ll s = x.size() + y.size();
	ll a = 1;
	while (a < s) a <<= 1;
	s = a;
	x.resize(s, 0);
	y.resize(s, 0);

	ll prime_base = ((ll)p.s << p.p)+1;
	fft(x, p);
	fft(y, p);
	for (ll i = 0; i < x.size(); i++) {
		x[i] = ((big)x[i]*y[i])%prime_base;
	}

	ifft(x, p);
}

char cb[3000000];
int _i = 0;
vector<ll> get_int(ll digs) {
	char c;
	int i = 0;
	while ((c=cb[_i++]) != '\n') {
		cb[i++] = c;
	}
	vector<ll> out((i+digs-1)/digs);
	ll x = 1;
	for (int j = 0, o = i-1; j < i; j++, o--) {
		if (j/digs != (j-1)/digs) x = 1;
		out[j/digs] += x*(cb[o]-'0');
		x *= 10;
	}
	return out;
}

int main() {
	fread(cb, 1, 3000000, stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll width = 7;
	vector<ll> a = get_int(width), b = get_int(width);

	//fft_prime p = { 45, 23, 7 };
	//fft_prime p = { 31, 60, 7 };
	fft_prime p = { 29, 57, 3 };
	//fft_prime p = { 3, 36, 11 };
	big pv = 1;
	pv <<= p.p;
	pv *= p.s;
	pv += 1;

	big x = pow(10, width, pv);
	big carry = 0;

	for (ll bits = 0; bits < p.p; bits++) {
		primitiveRoots[bits] = pow(pow(p.gen, p.s, pv), 1ll<<(p.p - bits), pv);
		pinv[bits] = pow(primitiveRoots[bits], pv-2, pv);
	}

	poly_mul(a, b, p);
	vector<ll> nnum;
	for (ll i : a) {
		carry += i;
		nnum.push_back(carry%x);
		carry /= x;
	}
	int start = nnum.size()-1;
	while (nnum[start] == 0 && start > 0) start--;
	if (start < 0) printf("0\n");
	else {
		cout << nnum[start];
		for (ll i = start-1; i >= 0; i--) cout << setfill('0') << setw(width) << nnum[i];
		cout << endl;
	}
}
