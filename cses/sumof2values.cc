#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
2 approaches to this problem:
    1. sort and binary search
    2. sort and use 2 pointers to exploit the relation b/w current sum and the
    actual sum (move left ptr if tempSum is < sum and otherwise if it's greater)
*/

// sort ascending
bool sortPair(pair<int, ll> &a, pair<int, ll> &b) {
    return a.second < b.second;
}

int main() {
    int n;
    ll sum;
    cin >> n >> sum;

    pair<int, ll> arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].first = i + 1;
        cin >> arr[i].second;
    }

    sort(arr, arr + n, sortPair);
    int l = 0, r = n - 1;

    while (l < r) {
        int tempSum = arr[l].second + arr[r].second;
        if (tempSum == sum) {
            cout << arr[l].first << " " << arr[r].first << endl;
            return 0;
        } else if (tempSum > sum) {
            r--;
        } else {
            l++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
