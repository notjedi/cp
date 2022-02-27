#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, ans = 0;
    cin >> n;

    ll a[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> tower_top;

    for (int i = 0; i < n; i++) {
        ll min_top = a[i];
        int idx = -1;

        for (int j = 0; j < tower_top.size(); j++) {
            if (a[i] - tower_top[j] < min_top)
                min_top = min(min_top, tower_top[j]);
            if (min_top == val)
                idx = j;
        }

        idx = idx == -1 ? idx : tower_top.size();
        tower_top[idx] = a[i];
    }

    cout << ans << endl;
    return 0;
}
