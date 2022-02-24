#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, ans = 0;
    cin >> n;

    ll a[n];
    map<ll, int> last_idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last_idx[a[i]] = -1;
    }

    int start_pos = 0;
    for (int i = 0; i < n; i++) {
        if (last_idx[a[i]] != -1) {
            ans = max(ans, i - start_pos);
            start_pos = max(start_pos, last_idx[a[i]] + 1);
        }
        last_idx[a[i]] = i;
    }

    ans = max(ans, n - start_pos);
    cout << ans << endl;
    return 0;
}
