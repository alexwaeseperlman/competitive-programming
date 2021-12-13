#include <bits/stdc++.h>
using namespace std;
 
int dp[1000001];
int main() {
    int n; cin >> n;
 
    for (int i = 1; i <= n; i++) {
        dp[i] = numeric_limits<int>::max()-1;
        int num = i;
        while (num) {
            dp[i] = min(dp[i], dp[i-num%10]+1);
            num /= 10;
        }
    }
    cout << dp[n] << endl;
}
