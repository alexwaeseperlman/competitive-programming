#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

const int N = 1000005; 

ull dp[N], factors[N], sum[N];

void fillFactors() {
	for (ull i = 1; i < N; i++) {
		for (ull j = i; j < N; j += i) factors[j]++;
	}
}

int main() {
	ull n; cin >> n;
	fillFactors();
	for (ull i = 1; i <= n; i++) {
		dp[i] = (factors[i] + sum[i - 1]) % 998244353ull;
		sum[i] = sum[i - 1] + dp[i];
	}
	cout << dp[n] << endl;
}
