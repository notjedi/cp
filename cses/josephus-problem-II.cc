#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using ll = long long;
using namespace __gnu_pbds;

#define ordered_set                                                            \
    tree<int, null_type, less<int>, rb_tree_tag,                               \
         tree_order_statistics_node_update>

int main() {
    ll n, k;
    cin >> n >> k;

    ll pos = k % n;
    ordered_set vals;
    for (ll i=1; i<=n; i++)
        vals.insert(i);

    while (vals.size() > 1) {
        ll temp = *vals.find_by_order(pos);
        vals.erase(temp);
        pos = (pos + k) % vals.size();
        cout << temp << " ";
    }
    cout << *vals.find_by_order(pos);
    return 0;
}
