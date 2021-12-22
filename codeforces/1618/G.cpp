#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200001], b[200001];
pair<ll, bool> items[400001];
ll dsu[400001], psum[400002];
struct group {
    ll starts = 0, first = 0, last = 0;
    ll size() {
        return last - first;
    }
    ll sum() {
        return psum[last] - psum[last-starts];
    }
};
group groups[400001];

struct edge {
    ll diff = 0, pos = 0;
    edge(ll diff, ll pos): diff(diff), pos(pos) {}
    const bool operator<(const edge &rhs) const {
        return rhs.diff < diff;
    }
};

ll sum = 0;

ll parent(ll i) {
    if (dsu[i] == i) return i;
    dsu[i] = parent(dsu[i]);
    return dsu[i];
}

void merge(ll i, ll j) {
    if (parent(i) != i || parent(j) != j) return merge(parent(i), parent(j));
    if (groups[i].size() < groups[j].size()) return merge(j, i);
    sum -= groups[i].sum() + groups[j].sum();
    dsu[j] = i;
    groups[i].last = max(groups[i].last, groups[j].last);
    groups[i].first = min(groups[i].first, groups[j].first);
    groups[i].starts += groups[j].starts;
    sum += groups[i].sum();
}

int main() {
    int n, m, q; cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        items[i].first = a[i];
        items[i].second = true;
    } 
    for (int i = 0; i < m; i++)  {
        cin >> b[i];
        items[i+n].first = b[i];
        items[i+n].second = false;
    }

    sort(items, items+n+m);
    for (ll i = 0; i < n+m; i++) {
        groups[i].first = i;
        groups[i].last = i+1;
        psum[i+1] = psum[i] + items[i].first;
        groups[i].starts = items[i].second;
        if (items[i].second) sum += items[i].first;
        dsu[i] = i;
    }
    
    priority_queue<edge> pq;
    for (ll i = 0; i < n+m-1; i++) {
        pq.emplace(items[i+1].first - items[i].first, i);
    }

    vector<pair<ll, ll>> ks(q);
    multimap<ll, ll> order;
    vector<ll> out(q);
    for (ll i = 0; i < q; i++) {
        cin >> ks[i].first;
        ks[i].second = i;
        order.emplace(ks[i].first, ks[i].second);
    } 
    sort(ks.begin(), ks.end());

    for (auto [k, idx] : order) {
        while (pq.size() && pq.top().diff <= k) {
            auto a = pq.top();
            pq.pop();
            merge(a.pos, a.pos+1);
        }
        out[idx] = sum;
    }
    for (ll i : out) cout << i << endl;
}
