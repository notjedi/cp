#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll a[n], sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (a[i] > sum + 1) {
            ans = sum + 1;
            break;
        }
        sum += a[i];
    }
    if (ans == 0)
        ans = sum + 1;
    cout << ans;
    return 0;
}
