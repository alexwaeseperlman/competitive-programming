#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000009;

ll mat[2][2] = { {0,1},
			   	 {1,1}};

ll out[2][2];

void matmul(ll a[2][2], ll b[2][2]) {
	out = { 
		{a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1]}, 
		{a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1]}, 
	};
}

int main() {
	ll n; cin >> n;
	for (ll i = 1; i <= mod; i++) {
		if (i&n) {
			
		}
		
	}



}
