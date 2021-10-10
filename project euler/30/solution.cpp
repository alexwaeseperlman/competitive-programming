#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
    int sum = 0;
    while (x) {
        int d = x%10;
        x /= 10;
        sum += d*d*d*d*d;
    }
    return sum;
}

int main() {
    int total = 0;
    for (int i = 2; i < 100000000; i++) {
        if (i == digitSum(i)) {
            total += i;
            cout << total << endl;
        }
    }
}