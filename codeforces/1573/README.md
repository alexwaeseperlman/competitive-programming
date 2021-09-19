# Contest 1573
This contest ended up being unrated so I stopped early (although to be honest I don't think I would have solved anything past C anyways).

## Problem A
The problem statement is here: https://codeforces.com/contest/1573/problem/A

I solved this in a few minutes by noticing a few things:
1. Making the clock show zero when it's currently in the form 0...0x (some number of zeros followed by x) takes a minimum of x steps.
2. Each digit can be treated individually. After changing the ones digit to zero using some number of '-1' operations, any other digit can be swapped in.
3. The total number of steps is the number of '-1' operations plus the number of swaps. We can calculate the number of '-1' operations by simply summing every digit, and we can calculate the number of swaps by counting the number of non-zero digits outside of the ones place.

The implementation is shown below. It runs in O(n) time
```c++
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;

	vector<int> nums(n);
	int digs = 0, total = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		nums[i] = c - '0';
		if (nums[i] != 0) digs++;
		total += nums[i];
	}
	cout << total + digs - 1 + (nums[n-1] == 0) << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
```


## Problem B
The problem statement is here: https://codeforces.com/contest/1573/problem/B

This was also a relatively straightforward solution. The important thing to notice is that since none of the digits are the same in array a and b, the only digit that matters for lexicographical ordering is the first one. We need to find the values of `i`, `j` such that `a[i] < b[j]`, minimizing `i + j`. I did this efficiently (O(n log n) time) by sorting each array and creating a map from each value of `j` to the smallest value of `i` such that `a[i] < b[j]`. It's simple to find the solution from there.

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> ap(n), bp(n);

	for (int i = 0; i < n; i++) {
		ap[(a[i]-1)/2] = i;
		bp[(b[i]-2)/2] = i;
	}

	int low = n;
	int steps = n;
	for (int i = 2; i <= 2*n; i+=2) {
		low = min(low, ap[(i - 1)/2]);
		if (low + bp[(i-2)/2] < steps) steps = low + bp[(i-2)/2];
	}
	cout << steps << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
```

## Problem C
The problem statement is here: https://codeforces.com/contest/1573/problem/C

This was an interesting problem. My trick for solving this was to think of the book as a directed graph where nodes are chapters and edges are requirements. In a reading of the book it's only possible to understand chapters once all the connected nodes have themselves been understood. The weight of an edge is `1` if it's going to a chapter that comes earlier, and `0` if it's going to a chapter that comes later. This is because it takes a whole new reading of the book to read, for example, chapter 3 after chapter 5, but chapter 5 is seen after chapter 3 in one reading. Once I noticed this I decided to use dynamic programming and landed on the following algorithm (O(n), where n is the number of edges).
1. Find all the chapters that have no dependencies and push them to the top of a dfs stack
2. Each time a chapter is visited check if the distances to all of its required chapters have been calculated yet
3. If not then skip this chapter (we'll come back to it)
4. If yes then calculate the distance to this chapter (max of distances to required chapters, +1 if an extra reading is necessary). Push every chapter that requires this one to the stack.
5. Once the stack is empty check if the distance to every chapter has been calculated yet. If it hasn't then the graph contains a circular dependency and there is no solution. If it has then return the maximum distance 

The implementation is too long to fit in this post, but it's in `C.cpp` in the folder

