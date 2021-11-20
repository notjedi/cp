#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=568 */
int main() {

  /* freopen("speeding.in", "r", stdin); */
  /* freopen("speeding.out", "w", stdout); */
  int n, m, speedLimit[100], lastSegment = 0, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int dist, limit;
    cin >> dist >> limit;
    for (int j = lastSegment; j < lastSegment + dist; j++)
      speedLimit[j] = limit;
    lastSegment = dist;
  }

  lastSegment = 0;
  for (int i = 0; i < m; i++) {
    int dist, speed;
    cin >> dist >> speed;
    for (int j = lastSegment; j < lastSegment + dist; j++)
      ans = max(ans, speed - speedLimit[j]);
    lastSegment = dist;
  }

  cout << ans;
  return 0;
}
