#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string dfs(ll max, char current='a', bitset<26*26> visited=bitset<26*26>(), string cycle="") {
	cycle += current;

	for (ll i = 0; i < max; i++) {
		ll idx = (current - 'a') * 26 + i;
		
		if (visited[idx]) continue;

		visited[(current - 'a') * 26 + i] = true;
		string s = dfs(max, 'a' + i, visited, cycle);
		visited[(current - 'a') * 26 + i] = false;

		
		if (s.size() > 0) return s;
	}


	for (ll i = 0; i < max; i++) {
		for (ll j = 0; j < max; j++) {
			if (visited[i * 26 + j] == false) return "";
		}
	}

	return cycle;
}

int main() {
	ll n, k;

	cin >> n >> k;
	string s = dfs(k);

	for (ll i = 0; i < n; i++) cout << s[i % (s.size()-1)];
	cout << endl;

}
