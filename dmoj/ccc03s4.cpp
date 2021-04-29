#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>

using namespace std;

struct suffixTree {
	map<char, suffixTree*> children;
	bool parent = false;
	
	void init(string &str, int i=0) {
		if (i >= str.size()) return;
		if (children.find(str[i]) == children.end()) {
			parent = true;
			children[str[i]] = new suffixTree();
		}
		children[str[i]]->init(str, i + 1);
	}

	unsigned long long countNodes() {
		unsigned long long n = children.size();
		for (auto i : children) n += i.second->countNodes();
		return n;
	}

	~suffixTree() {
		if (!parent) return;
		for (auto i : children) delete i.second;
	}
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		suffixTree tree;
		string s;
		cin >> s;
		
		for (int j = 0; j < s.size(); j++) {
			tree.init(s, j);
		}

		cout << tree.countNodes() + 1 << endl;
	}
}
