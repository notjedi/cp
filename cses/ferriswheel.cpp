#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    int n, total = 0;
    ll x;
    cin >> n >> x;
    ll weights[n];
 
    for (int i=0; i<n; i++)
        cin >> weights[i];
    sort(weights, weights+n);

    int i=0, j=n-1;
    while (i < j) {
        if (weights[i] + weights[j] <= x)
            i++;

        j--;
        total++;
        if (i == j) {
            total++;
            break;
        }
    }
    cout << total;
}
