#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll l, n, temp;
    cin >> l >> n;
    ll start = 0, end = l, max_l = 0;

    set<ll> pos;
    pos.insert(0);
    pos.insert(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pos.insert(temp);

        // left of start
        auto low_start = pos.lower_bound(start);
        if (low_start != pos.end())
            max_l = max(start - *low_start, max_l);

        // left of end
        auto low_end = pos.lower_bound(end);
        if (low_end != pos.end())
            max_l = max(end - *low_end, max_l);

        // right of start
        auto up_start = pos.upper_bound(start);
        if (low_end != pos.end())
            max_l = max(*up_start - start, max_l);

        // right of end
        auto up_end = pos.upper_bound(end);
        if (low_end != pos.end())
            max_l = max(*up_start - end, max_l);

        if (temp > start) {
            if (temp - start > end - temp) {
                end = temp;
                max_l = temp - start;
            } else {
                start = temp;
                max_l = end - temp;
            }
        }
        // cout << temp << " " << temp - start << " " << end - temp << " " <<
        // max_l
        //      << endl;
        cout << max_l << " ";
    }
}
