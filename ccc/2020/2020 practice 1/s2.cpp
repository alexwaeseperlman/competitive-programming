#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	queue<char> q;
	deque<char> s;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		q.push(c);
	}

	while (q.size()) {
		if (q.front() <= s[0]) s.push_front(q.front());
		else s.push_back(q.front());
		q.pop();
	}
	for (char c : s) cout << c;
	cout << endl;
}
