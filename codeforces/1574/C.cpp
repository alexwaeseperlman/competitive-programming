#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n; cin >> n;
  ll sum = 0;
  set<ll> heroes;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    heroes.insert(x);
    sum += x;
  }

  ll m; cin >> m;
  for (ll i = 0; i < m; i++) {
    ll d, a; cin >> d >> a;

    auto k = (heroes.lower_bound(d-1));
    if (k != heroes.begin()) k = prev(k);
    ll out = numeric_limits<ll>::max();
    for (int j = 0; j < 3 && k != heroes.end(); j++) {
      out = min(out, max(0ll, d-*k) + max(0ll, a-sum+*k));
      k = next(k);
    }
    cout << out << endl;
  }
}