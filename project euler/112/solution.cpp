#include <bits/stdc++.h>
using namespace std;

bool bouncy(int n) {
    if (n < 100) return false;
    int d = n%10;
    n/=10;
    bool dec = false, inc = false;
    while (n) {
        int c = n % 10;
        if (c < d) dec = true;
        if (c > d) inc = true;
        n /= 10;
        d = c;
        if (dec && inc) return true;
    }
    return false;
}

int main() {
    int count = 0, i = 99;
    do {
        i++;
        if (bouncy(i)) count++;
        if ((double)count/(double)i == 0.5) {
            cout << count << " " << i << endl;
        }
    } while ((double)count/(double)i != 0.99);
    cout << count << " " << i << endl;
}