#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int counts[2000001], nc[2000001];

int main() {
	int n, x; cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i : c) counts[i] = 1;


	for (int i = 0; i < 1000000; i++) {
		for (int k = 0; k < 1000000; k++) {
			for (int j = 0; j < n; j++) {
				nc[k+c[j]] += counts[k];
				nc[k+c[j]] %= mod;
			}
		}

		copy(nc, nc+1000001, counts);
		fill(nc, nc+1000001, 0);
	}

	cout << counts[x] << endl;;



}
#include <bits/stdc++.h>
using namespace std;
 
const int base = 1000000007;
 
int dp[1000001];
int main() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i <= x; i++) {
        for (int v : c) {
            if (i - v >= 0) {
                dp[i] = (dp[i]+dp[i-v])%base;
            }
        }
    }
    cout << dp[x] << endl;
}
