#include <bits/stdc++.h>
using namespace std;
using ll = long long;
  
  
void solve() {
  ll s, n; cin >> s >> n;
  
  vector<ll> out(n, 0);
  ll zeros = n-1;
  
  ll i = 1;
  while (i < s) i *= 10;
  while (s > 0 && zeros > 0) {
    while (s-i >= zeros) {
      out[zeros == -1 ? 0 : zeros] += i;
      s -= i;
      if (zeros != -1) zeros--;
    }
    i /= 10;
  }
  out[0] += s;
  
  for (ll i = 0; i < n; i++) {
    cout << out[i] << " ";
  }
  cout << endl;
}
  
  
  
int main() {
  int t; cin >> t;
  
  while (t--) solve();
}
