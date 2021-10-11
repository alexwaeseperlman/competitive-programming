#include <bits/stdc++.h>
#include "../../algorithms/modular_arithmetic.h"
using namespace std;
using namespace number_theory;

int main() {
    mod_int sum(0, 10000000000ll);
    for (ll i = 1; i <= 1000ll; i++) {
        //for some reason these powers aren't calculated correctly
        cout << i <<": "<< mod_int(i, 10000000000ll).pow(i) << endl;
    }
    cout << sum << endl;
}