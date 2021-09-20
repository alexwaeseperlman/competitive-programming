#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;

  string a = "";
  for (int i = 0; i < n; i++) {
    a = "(" + a + ")";
  }

  cout << a << endl;
  for (int i = 1; i < n; i++) {
    string s = a;
    s[i] = ')';
    s[s.size()-i-1] = '(';
    cout << s << endl;
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
}