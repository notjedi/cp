#include<bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://www.cplusplus.com/reference/set/set/lower_bound/ */
/* https://codeforces.com/blog/entry/17077 */
/* https://stackoverflow.com/questions/55392781/how-to-use-lower-bound-on-set-of-pairs */

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<ll, int>> prices;
    ll pay[m];

    for (int i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        prices.insert(make_pair(temp, i));
    }
    for (int i=0; i<m; i++)
        cin >> pay[i];

    for (int i=0; i<m; i++) {
        auto match = prices.lower_bound({pay[i]+1, numeric_limits<int>::min()});
        /* cout << pay[i] << " " << (*match).first << endl; */
        if (match == prices.begin()) {
            cout << "-1" << endl;
        } else {
            --match;
            cout << (*match).first << endl;
            prices.erase(match);
        }
    }

}
