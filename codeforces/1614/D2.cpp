#pragma GCC optimize "O3"
#pragma GCC target "avx2"
#include <bits/stdc++.h>
using namespace std;
 
const int maxA = 20000000;
 
long long a[100001], counts[maxA+1]; 
long long dp[maxA+1];
bitset<maxA+1> prime;

int gp[maxA+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long long high = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		counts[a[i]] += 1;
		high = max(high, a[i]);
	}
	prime.flip();
	for (int i = 2; i <= high; i++) {
		if (prime[i]) {
			for (int j = i; j <= high; j += i) {
				if (j > i) prime[j] = false;
				gp[j] = i;
				if (counts[j]) {
					bool power = false;
					for (int x = i; j%x == 0; x *= i) {
						counts[j/x]+=counts[j];
					}
				}
			}
		}
	}
 
	dp[1] = n;
	long long best = dp[1];
	for (long long i = 2; i <= high; i++) {
		//if (counts[i] == 0) continue;
		
		int x = i;
		for (long long j = gp[x]; x > 1; x /= j, j = gp[x]) {
			long long a = i/j;
			dp[i] = max(dp[i], dp[a] + (counts[i])*(i-a));
		}
		best = max(dp[i], best);
	}
	cout << best << endl;
}
