#include <bits/stdc++.h>
using namespace std;

int axor(int k) {
  if (k % 2 == 1) {
    if (((k - 1) / 2) % 2 == 1) return 0;
    else return 1;
  }
  else return k + ((k / 2) % 2);
}

void solve() {
  int m, x; cin >> m >> x;

  int a = axor(m-1);
  if (a != x) {
    if ((a ^ m) == x) {
      cout << m + 2 << endl;
    }
    else {
      cout << m + 1 << endl;
    }
  }
  else cout << m << endl;
}



int main() {
  int t; cin >> t;

  while (t--) solve();
}
