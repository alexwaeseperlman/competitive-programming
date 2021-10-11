#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull N = 1000000;
bitset<N> notPrime;
vector<ull> primes, psum;

int main() {
    psum.push_back(0);
    for (ull i = 2; i <= N; i++) {
        if (!notPrime[i]) {
            psum.push_back(psum[psum.size()-1]+i);
            primes.push_back(i);
            for (ull j = 2*i; j <= N; j+=i) {
                notPrime[j] = true;
            }
        }
    }

    ull m = 0, mp = 0;
    for (ull len = 2; len < primes.size()-1; len++) {
        for (ull i = 0; i < primes.size()-len; i++) {
            if (psum[i+len]-psum[i] < N && !notPrime[psum[i+len]-psum[i]]) {
                if (len > m) {
                    m = len;
                    mp = psum[i+len] - psum[i];
                    cout << mp << " " << m << endl;
                    for (ull j = i; j < i+len; j++) cout << primes[j]<< " ";
                    cout << endl;
                }
            }
        }
    }

    cout << mp << endl;

}