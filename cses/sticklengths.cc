#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll arr[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int middle = n / 2;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - arr[middle]);
    }
    cout << sum << endl;
    return 0;
}
