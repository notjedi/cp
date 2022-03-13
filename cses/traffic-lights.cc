#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://usaco.guide/problems/cses-1163-traffic-lights/solution */
int main() {

    // this actually helped this time, lol.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, n, temp;
    cin >> l >> n;

    multiset<ll> dist;
    set<ll> pos;
    dist.insert(l);
    pos.insert(0);
    pos.insert(l);

    for (ll i = 0; i < n; i++) {
        cin >> temp;

        auto up_bound = pos.upper_bound(temp);
        auto low_bound = up_bound;
        --low_bound;

        dist.erase(dist.find(*up_bound - *low_bound));
        dist.insert(temp - *low_bound);
        dist.insert(*up_bound - temp);
        pos.insert(temp);

        cout << *--dist.end() << " ";
    }

    return 0;
}
