#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  while (n--) {
    char s; cin >> s;
    switch (s) {
      case 'L': cout << 'L'; break;
      case 'R': cout << 'R'; break;
      case 'U': cout << 'D'; break;
      case 'D': cout << 'U'; break;
    }
  }
  cout << endl;
}

int main() {
  int t; cin >> t;

  while (t--) solve();
}
