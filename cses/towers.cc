#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    multiset<ll> tower;
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        auto lower_bound = tower.upper_bound(val);

        if (lower_bound != tower.end())
            tower.erase(lower_bound);
        tower.insert(val);
    }
    cout << tower.size() << endl;
}
