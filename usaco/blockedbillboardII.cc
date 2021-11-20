#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Rect {
  int x1, y1, x2, y2;
  int area() { return ((x2 - x1) * (y2 - y1)); }
};

int intersection(Rect a, Rect b) {
  int x = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
  int y = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
  cout << x << " " << y << " " << x * y << endl;
  return (x * y);
}

int solve(Rect a, Rect b) {

  int x, y;
  if ((a.x1 - b.x1) == 0)
    y = abs(a.y2 - b.y2);
  else
    y = abs(a.y2 - a.y1);

  if ((a.y1 - b.y1) == 0)
    x = abs(a.x1 - b.x1);
  else
    x = abs(a.x2 - a.x1);

  return (x * y);
}

int main() {

  /* tarp needs to be a rectangle */
  /* freopen("billboard.in", "r", stdin); */
  /* freopen("billboard.out", "w", stdout); */
  Rect lawn, cow;
  cin >> lawn.x1 >> lawn.y1 >> lawn.x2 >> lawn.y2;
  cin >> cow.x1 >> cow.y1 >> cow.x2 >> cow.y2;
  int ans = solve(lawn, cow);
  cout << ans;
  return 0;
}
