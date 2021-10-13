    #include <bits/stdc++.h>
    using namespace std;
    using ull = unsigned long long;
     
    void solve() {
    	ull n, k; cin >> n >> k;
     
    	ull p = 0;
    	for (ull i = 0; i < n; i++) {
    		cout << (i^p) << endl;
    		cout.flush();
    		ull r; cin >> r;
    		if (r) return;
     
    		p = i;
    	}
    }
     
    int main() {
    	int t; cin >> t;
    	while (t--) solve();
    }
