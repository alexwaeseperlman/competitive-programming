#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
ll N;
 
struct node {
    ll lazy = 0, lazyStart = 0, val = 0;
    ll subtreeSize = 0;
    ll delayed() {
        return ((lazy*subtreeSize*(subtreeSize+1))>>1) + (lazyStart*subtreeSize);
    }
} segtree[400002];
 
node merge(node a, node b) {
    node out;
    out.val = a.val+b.val;
    out.val += a.delayed() + b.delayed();
    out.subtreeSize = a.subtreeSize+b.subtreeSize;
    return out;
}
 
void push(ll pos) {
    segtree[pos].val += segtree[pos].delayed();
    if (pos <= N) {
        segtree[pos<<1|1].lazy += segtree[pos].lazy;
        segtree[pos<<1|1].lazyStart += segtree[pos].lazy*segtree[pos<<1].subtreeSize + segtree[pos].lazyStart;
 
        segtree[pos<<1].lazy += segtree[pos].lazy;
        segtree[pos<<1].lazyStart += segtree[pos].lazyStart;
    }
    segtree[pos].lazy = 0;
    segtree[pos].lazyStart = 0;
}
 
void fall(ll pos) {
    int log = 0;
    while (1<<log < pos) log++;
    for (int i = log-1; i >= 0; i--) push(pos>>i);
}
 
void up(int x) {
    while (x>1) x >>= 1, push(x), segtree[x] = merge(segtree[x<<1], segtree[x<<1|1]);
}
 
void build() {
    for (ll i = N; i >= 1; i--) {
        segtree[i] = merge(segtree[i<<1|1], segtree[i<<1]);
    }
}
 
ll sum(ll l, ll r) {
    ll out = 0;
    fall(l+N); fall(r+N);
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
        out += (segtree[l].val+segtree[l].delayed())*(l&1);
        l+=l&1;
        out += (segtree[r].val+segtree[r].delayed())*(~r&1);
        r-=~r&1;
    }
    return out;
}
 
void add(ll l, ll r) {
    ll add = 1, base = r-l;
    ll pl = 0, pr = 0;
    ll l0 = l+N, r0 = r+N;
 
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
        segtree[l].lazy += add*(l&1);
        segtree[l].lazyStart += pl*(l&1);
        pl += segtree[l].subtreeSize*(l&1);
        l+=l&1;
        segtree[r].lazy += add*(~r&1);
        pr += segtree[r].subtreeSize*(~r&1);
        segtree[r].lazyStart += (base+1 - pr)*(~r&1);
        r-=~r&1;
    }
    up(l0);
    up(r0);
}
 
void print() {
    for (ll i = 1; i <= N; i++) {
        cout << sum(i,i) << " ";
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll q; cin >> N >> q;
 
    for (ll i = N+1; i <= 2*N; i++) {
        cin >> segtree[i].val;
        segtree[i].subtreeSize = 1;
    }
 
    build();
    while (q--) {
        ll type, l, r; cin >> type >> l >> r;
        if (type == 1) add(l, r);
        else cout << sum(l, r) << endl;
    }
 
}
