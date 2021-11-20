#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

bool sortPair(pair<ll, int> &a, pair<ll, int> &b) {
    return a.first < b.first;
}

int main() {

    int n, maxCustomers = 0, temp = 0;
    cin >> n;
    pair<ll, int> events[n*2];

    for (int i=0; i<n; i++) {
        ll start, end;
        cin >> start >> end;
        events[temp] = make_pair(start, 1);
        events[temp+1] = make_pair(end, -1);
        temp += 2;
    }
    sort(events, events+(2*n), sortPair);

    temp = 0;
    for (auto event: events) {
        temp += event.second;
        /* cout << event.second << " " << temp << endl; */
        maxCustomers = max(temp, maxCustomers);
    }
    cout << maxCustomers;
}
