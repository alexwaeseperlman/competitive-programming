#include <bits/stdc++.h>
using namespace std;

int parent[81];
int getParent(int a) {
	if (parent[a] == a) return a;
	parent[a] = getParent(parent[a]);
	return parent[a];
}
bool connected(int a, int b) {
	return getParent(a) == getParent(b);
}
void join(int a, int b) {
	parent[getParent(a)] = getParent(b);
}

int main() {
	int n, m; cin >> n >> m;

	vector<pair<int, int>> ant(n);

	for (int i = 0; i < n; i++) {
		cin >> ant[i].first >> ant[i].second;
	}
	sort(ant.begin(), ant.end());



}
