#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L; cin >> N >> L;
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    int best = 0;
    for (int i = 1; i <= N; i++) {
        int lb = 0, ub = N;
        while (lb < ub) {
            int m = (ub+lb)/2;
            if (c[m] < i) ub = m;
            else lb = m+1;
        }

        if (c[i-1] >= i-1 && i - lb <= L) best = i;
    }
    cout << best << endl;
}
