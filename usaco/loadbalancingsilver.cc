#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int MAX_NUM = numeric_limits<int>::max();

/* more faster solutions at
 * https://usaco.guide/bronze/intro-complete#problem-usaco-619 */

/* the trick i'm using is nasty and is not guaranteed to always work
 * and is 2-3x(on large solution space inputs) slower than the other solns
 * posted there */

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=619 */
int main() {

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  int n, maxCows = MAX_NUM, sumX = 0, sumY = 0;
  int minX = MAX_NUM, minY = MAX_NUM, maxX = 0, maxY = 0;
  cin >> n;
  vector<int> xval(n), yval(n), xfence(n), yfence(n);
  for (int i = 0; i < n; i++) {
    cin >> xval[i] >> yval[i];
    xfence[i] = xval[i] + 1;
    yfence[i] = yval[i] + 1;
    sumX += xval[i];
    sumY += yval[i];
    minX = min(minX, xval[i]);
    minY = min(minY, yval[i]);
    maxX = max(maxX, xval[i]);
    maxY = max(maxY, yval[i]);
  }
  sumX /= n;
  sumY /= n;
  int midX = (maxX - minX) / 4, midY = (maxY - minY) / 4;

  for (auto i = xfence.begin(); i != xfence.end(); i++) {
    for (auto j = yfence.begin(); j != yfence.end(); j++) {
      if (!(*i<sumX + midX && * i> sumX - midX))
        continue;
      if (!(*j<sumY + midY && * j> sumY - midY))
        continue;
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
