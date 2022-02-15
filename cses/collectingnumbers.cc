#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, ans = 1;
    cin >> n;

    int a[n], b[n + 1] = {0};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    b[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (b[a[i] - 1] == 0)
            ans++;
        b[a[i]] = 1;
    }
    cout << ans << endl;
    return 0;
}
