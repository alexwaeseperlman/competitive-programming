#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

bool pandigital(ull n, ull b) {
    vector<bool> has(b);

    while (n) {
        ull d = n % b;
        n /= b;
        has[d] = true;
    }

    for (ull i = 0; i < b; i++) if (!has[i]) return false;
    return true;
}

int main() {
    ull sum = 0, count = 0;
    vector<ull> digs{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int iters = 0;
    do {
        if (digs[0] == 0) continue;
        ull n = 0;
        for (ull i = 0; i < digs.size(); i++) {
            n *= digs.size();
            n += digs[i];
        }
        if (iters % 1000000 == 0) cout << iters << " " << n << endl;
        iters++;

        bool s = true;
        for (ull b = 2; b < 12; b++) {
            if (!pandigital(n, b)) {
                s = false;
                break;
            }
        }
        if (s) {
            sum += n;
            count++;
            cout << n << " " << count << " " << sum << endl;
            if (count == 10) break;
        }

    } while (next_permutation(digs.begin(), digs.end()));
    cout << sum << " " << count << endl;
}