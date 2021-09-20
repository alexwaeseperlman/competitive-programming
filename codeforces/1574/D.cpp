#include <bits/stdc++.h>

using namespace std;

struct Node {
  map<int, Node*> children;
  int n;
  Node(int n, vector<vector<int>> &seqs, int seq_start = 0): n(n) {
    for (int i = 0; i < seqs.size(); i++) {
      if (seq_start >= seqs[i].size() || children[seqs[i][seq_start]]) continue;
      children[seqs[i][seq_start]] = new Node(seqs[i][seq_start], seqs, seq_start+1);
    }
  }
  
  bool test(vector<int> &seq, int i=0) {
    if (i+1 == seq.size()) return true;
    if (!children[seq[i]]) return false;
    else return children[seq[i]]->test(seq, i+1);
  }
}

int main() {
  int n; cin >> n;
  vector<set<int>> slots(n);
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int l; cin >> l;
      slots[i].insert(l);
    }
  }
  
}