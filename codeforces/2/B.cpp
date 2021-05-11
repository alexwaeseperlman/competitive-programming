#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
pair<ll, ll> dp[1001][1001], arr[1001][1001];
pair<char, char> paths[1001][1001];
 
pair<ll, ll> mins(ll i, ll j, ll n) {
	if (dp[i][j].first != -1) return dp[i][j];
	else {
		pair<ll, ll> out;
		if (j > 0 && i > 0) {
			auto p1 = mins(i, j-1, n);
			auto p2 = mins(i-1, j, n);
 
			out.first = min(p1.first, p2.first);
			if (out.first == p1.first) paths[i][j].first = 'R';
			else paths[i][j].first = 'D';
 
			out.second = min(p1.second, p2.second);
			if (out.second == p1.second) paths[i][j].second = 'R';
			else paths[i][j].second = 'D';
		}
		else if (j > 0) {
			paths[i][j] = {'R', 'R'};
			out = mins(i, j-1, n);
		}
		else if (i > 0) {
			paths[i][j] = {'D', 'D'};
			out = mins(i-1, j, n);
		}
 
		out.first += arr[i][j].first;
		out.second += arr[i][j].second;
 
		dp[i][j] = out;
		return out;
	}
 
}
 
pair<ll, ll> twosFives(ll n) {
	if (n == 0) return {1,1};
	pair<ll, ll> out;
 
	for (; n % 2 == 0; out.first++, n /= 2);
	for (; n % 5 == 0; out.second++, n /= 5);
 
	return out;
}
 
int main() {
	ll n; cin >> n;
	bool containsZero = false;
	pair<int, int> zeroPos;
 

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		ll n; cin >> n;
		if (n == 0) {
			containsZero = true;
			zeroPos = {i, j};
		}
		arr[i][j] = twosFives(n);
	}
 
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = {-1, -1};
 
	auto p = mins(n-1, n-1, n);
	if (containsZero && min(p.first, p.second) > 1) {
		cout << 1 << endl;
		for (int i = 0; i < zeroPos.first; i++) {
			cout << 'D';
		}
		for (int i = 0; i < zeroPos.second; i++) cout << 'R';
		int i = zeroPos.first, j = zeroPos.second;
		while (++i < n) cout << 'D';
		while (++j < n) cout << 'R';
		cout << endl;
		return 0;
	}
	cout << min(p.first, p.second) << endl;
 
	string out;
	int i = n-1, j=n-1;
	while (i > 0 || j > 0) {
		char dir;
		if (p.first < p.second) dir = paths[i][j].first;
		else dir = paths[i][j].second;
		out += dir;
		if (dir == 'R') j--;
		else i--;
	}
 
	reverse(out.begin(), out.end());
	cout << out << endl;
 
}
