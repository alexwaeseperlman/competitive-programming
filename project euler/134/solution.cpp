#include <bits/stdc++.h>
#include "../../algorithms/modular_arithmetic.h"

using namespace std;
using namespace number_theory;

const ull N = 2000000;
bitset<N+1> notPrime;
vector<ull> primes;


int main() {
    for (ull i = 2; i < N; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (ull j = 2*i; j<=N; j += i) {
                notPrime[j] = true;
            }
        }
    }

    ull sum = 0;
    for (ull i = 0; primes[i] < 1000000; i++) {
        if (primes[i] < 5) continue;
        mod_int p1(primes[i], primes[i+1]);
        ull digits = (log10(primes[i])) + 1;
        ull digits10 = exp10(digits);
        mod_int inverse = mod_int(digits10, primes[i+1]).inverse();
        ull k = (-p1 * inverse).get_val();

        sum += k * digits10 + primes[i];


        if ((k*digits10 + primes[i]) % primes[i+1] != 0) {
            cout << digits << " " << primes[i] << " " << primes[i+1] << " " << k << " " << k*digits + primes[i] << endl;
        }
    }
    cout << sum << endl;
}