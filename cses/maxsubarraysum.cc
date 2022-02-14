#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll curr_max = 0, global_max = arr[0];
    for (int i = 0; i < n; i++) {
        curr_max = max(arr[i], curr_max + arr[i]);
        global_max = max(curr_max, global_max);
    }

    cout << global_max << endl;
    return 0;
}
