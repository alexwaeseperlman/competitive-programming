#include <bits/stdc++.h>
using namespace std;

int counts[100001];

int main() {
	int n; cin >> n;
	deque<int> s;
	for (int i = 0; i < n; i++) {
		int a = 0; cin >> a;
		counts[a]++;
	}
	for (int i = 0; i <= 100000; i++) {
		if (counts[i]) s.push_back(i);
	}

	bool sl = true;
	while (s.size() >= 3) {
		int front = s.front(), back = s.back();
		sl = counts[front] > counts[back];
		if (sl) {
			counts[front] -= counts[back];
			counts[s[1]] += counts[back];
			counts[s[s.size()-2]] += counts[back];
			counts[back] = 0;
			s.pop_back();
		}
		else if (counts[front] == counts[back]) {
			sl=true;
			counts[front] = 0;
			s.pop_front();
			s.pop_back();
			counts[s.front()] += counts[back];
			counts[s.back()] += counts[back];
			counts[back] = 0;
		}
		else {
			counts[back] -= counts[front];
			counts[s[s.size()-2]] += counts[front];
			counts[s[1]] += counts[front];
			counts[front] = 0;
			s.pop_front();
		}
	}
	if (sl) cout << "Slavko" << endl;
	else cout << "Mirko" << endl;

	cout << s.front() << " " << s.back() << endl;
}
