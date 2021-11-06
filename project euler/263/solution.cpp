#include <bits/stdc++.h>
using namespace std;
const int N = 2000000000;

vector<bool> notPrime(N);

bool triplet(int n) {
  int sum = 0;
  for (int i = -9; i <= 9; i++) {
    sum += !notPrime[i+n];
  } 

  return sum == 4 && !notPrime[n-9] && !notPrime[n-3] && !notPrime[n+3] && !notPrime[n+9];
}

bool practical(int n);

bool pracAround(int n) {
  for (int i = -8; i <= 8; i+=4) {
    if (!practical(n+i)) return false;
  }
  return true;
}

bool practical(int n) {
  int sn = sqrt(n);
  stack<int> large;
  int sum = 0;
  for (int i = 1; i <= sn; i++) {
    if (n % i == 0) {
      if (sum + 1 >= i) {
        sum += i;
        large.push(n/i);
        if (sum >= n) return true;
      }
      else return false;
    }
  }
  while (large.size()) {
    int top = large.top();
    large.pop();
    if (sum +1 >= top) sum += top;
    else return false;
    if (sum >= n) return true;
  }
  cout << n << " " << sum << endl;
  return false;
}


int main() {
  int sn = sqrt(N)+1;
  for (int i = 2; i <= sn; i++) {
    if (!notPrime[i]) {
      for (int j = 2*i; j < N; j+=i) {
        notPrime[j] = true;
      }
    }
    if (i % 100000 == 0) cout << i << endl;
  }

  long long sum = 0;
  for (int i = 9; i < N-100; i++) {
    if (triplet(i) && pracAround(i)) {
      cout << i << endl;
      sum += i;
    }
  }
  cout << sum << endl;
}
