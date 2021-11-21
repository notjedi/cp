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
  return (x * y);
}

int solve(Rect a, Rect b) {

  int x, y, ans;
  if ((a.x1 >= b.x1 && a.x2 <= b.x2) || (a.y1 >= b.y1 && a.y2 <= b.y2)) {
    ans = a.area() - intersection(a, b);
  } else {
    x = a.x2 - a.x1;
    y = a.y2 - a.y1;
    ans = abs(x * y);
  }
  return ans;
}

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=783 */
int main() {

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  Rect lawn, cow;
  cin >> lawn.x1 >> lawn.y1 >> lawn.x2 >> lawn.y2;
  cin >> cow.x1 >> cow.y1 >> cow.x2 >> cow.y2;
  int ans = solve(lawn, cow);
  cout << ans << endl;
  return 0;
}
