#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n + 2], idx[n + 2], mark[n + 2] = {0}, ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    idx[0] = -1;
    idx[n + 1] = n;
    mark[arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (mark[arr[i] - 1] == 0)
            ans++;
        mark[arr[i]] = 1;
    }

    int i = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int oldAPos = idx[arr[a]], oldBPos = idx[arr[b]];
        swap(arr[a], arr[b]);
        swap(idx[arr[a]], idx[arr[b]]);

        if (idx[arr[b]] < idx[arr[b] + 1] && oldAPos >= idx[arr[b] + 1])
            ans--;
        if (idx[arr[b]] >= idx[arr[b] + 1] && oldAPos < idx[arr[b] + 1])
            ans++;
        if (idx[arr[b]] < idx[arr[b] - 1] && oldAPos >= idx[arr[b] - 1])
            ans++;
        if (idx[arr[b]] >= idx[arr[b] - 1] && oldAPos < idx[arr[b] - 1])
            ans--;

        if (idx[arr[a]] < idx[arr[a] + 1] && oldBPos >= idx[arr[a] + 1])
            ans--;
        if (idx[arr[a]] >= idx[arr[a] + 1] && oldBPos < idx[arr[a] + 1])
            ans++;
        if (idx[arr[a]] < idx[arr[a] - 1] && oldBPos >= idx[arr[a] - 1])
            ans++;
        if (idx[arr[a]] >= idx[arr[a] - 1] && oldBPos < idx[arr[a] - 1])
            ans--;

        cout << ans << endl;
        cout << endl << endl << endl;
    }
    return 0;
}
