#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {

    int n, m;
    ll k;
    cin >> n >> m >> k;

    ll desired[n], size[m];
    for (int i=0; i<n; i++)
        cin >> desired[i];
    for (int i=0; i<m; i++)
        cin >> size[i];
    
    sort(desired, desired + n);
    sort(size, size + m);

    int i = 0, j=0, count = 0;
    while (i < n && j < m) {
        if (size[j] < desired[i] - k) {
            j++;
        } else if (size[j] >= desired[i] - k && size[j] <= desired[i] + k) {
            j++;
            i++;
            count++;
        } else {
            i++;
        }
    }
    cout << count;
}
