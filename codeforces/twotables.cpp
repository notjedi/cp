#include<bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

struct Rect{
    int x1, x2, y1, y2;
    int area() {
        return ((x2 - x2) * (y2 - y1));
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long W, H, x1, x2, y1, y2, w, h, dx, dy;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        dx = dy = numeric_limits<long long>::max();
        long long a = x1, b = (W - x2);
        long long c = y1, d = (H - y2);

        if (w > (W - (x2 - x1)) && h > (H - (y2 - y1))) {
            cout << -1 << endl;
            continue;
        }

        if (a+b >= w)
            dx = min(max(0ll, w-a), max(0ll, w-b));
        if (c+d >= h)
            dy = min(max(0ll, h-c), max(0ll, h-d));

        cout << min(dx, dy) << endl;
    }

    return 0;
}
