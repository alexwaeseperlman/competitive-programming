#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct C {
    C *b = 0, *a = 0;
    ll i;
};

unordered_map<ll, C> t;
unordered_map<ll, vector<ll>> m;

int main() {
    ll n; cin >> n;

    for (ll i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        m[l].push_back(r);
        m[r].push_back(l);

        if (n == 1) {
            cout << l << " " << r << endl;
            return 0;
        }
    }

    auto p = m.begin();
    while (p->second.size() < 2) p++;

    C *c = &t[p->first];

    c->b = &t[p->second[0]];
    c->b->i = p->second[0];
    c->i = p->first;

    C *i = c;
    for (ll _ : {1, -1}) {
        i = c;
        while (m[i->i].size() > 1) {
            C *&n = _ == 1 ? i->a : i->b;
            C *&p = _ == 1 ? i->b : i->a;

            ll I = -1;
            if (p->i == m[i->i][0]) I = m[i->i][1];
            else I = m[i->i][0];

            n = &t[I];
            n->i = I;
            if (_ == 1) n->b = i;
            else n->a = i;
            i = n;
        }
    }

    while (i) {
        cout << i->i << " ";
        i = i->a;
    }
    cout << endl;
}
