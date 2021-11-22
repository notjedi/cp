#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=617 */
int main() {

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  int n, b, maxCows = numeric_limits<int>::max();
  cin >> n >> b;
  vector<int> xval(n), yval(n), xfence(n), yfence(n);
  for (int i = 0; i < n; i++) {
    cin >> xval[i] >> yval[i];
    xfence[i] = xval[i] + 1;
    yfence[i] = yval[i] + 1;
  }

  for (auto i = xfence.begin(); i != xfence.end(); i++) {
    for (auto j = yfence.begin(); j != yfence.end(); j++) {
      int topLeft, topRight, bottomLeft, bottomRight;
      topLeft = topRight = bottomLeft = bottomRight = 0;
      for (int k = 0; k < n; k++) {
        if (xval[k] > *i && yval[k] < *j)
          bottomRight++;
        else if (xval[k] < *i && yval[k] < *j)
          bottomLeft++;
        else if (xval[k] > *i && yval[k] > *j)
          topRight++;
        else if (xval[k] < *i && yval[k] > *j)
          topLeft++;
      }
      int ans = max({topLeft, topRight, bottomLeft, bottomRight});
      maxCows = min(maxCows, ans);
    }
  }

  cout << maxCows;
  return 0;
}
