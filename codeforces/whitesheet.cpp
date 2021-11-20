#include<bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

struct Rect {

    long long x1, x2, y1, y2;
    long long area() {
        return (x2 - x1) * (y2 - y1);
    }
};

long long intersectionThreeRect(Rect a, Rect b, Rect c) {
    long long x = max(0ll, min({a.x2, b.x2, c.x2}) - max({a.x1, b.x1, c.x1}));
    long long y = max(0ll, min({a.y2, b.y2, c.y2}) - max({a.y1, b.y1, c.y1}));
    return (x * y);
}

long long intersection(Rect a, Rect b) {
    long long x = max(0ll, min(a.x2, b.x2) - max(a.x1, b.x1));
    long long y = max(0ll, min(a.y2, b.y2) - max(a.y1, b.y1));
    return (x * y);
}

int main() {

    Rect white, black1, black2;
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

    ll area = white.area() - intersection(white, black1) - intersection(white, black2) + intersectionThreeRect(white, black1, black2);
    if (area > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
