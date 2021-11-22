#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int startPts[26], endPts[26];
int pairs = 0;

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=712 */

/* TRICK:
 * https://usaco.guide/problems/usaco-712-why-did-the-cow-cross-the-road-ii/solution
 */
int main() {

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
  string s;
  cin >> s;

  fill_n(startPts, 26, -1);
  fill_n(endPts, 26, -1);

  for (int i = 0; i < s.length(); i++) {
    if (startPts[s[i] - 'A'] == -1)
      startPts[s[i] - 'A'] = i;
    else
      endPts[s[i] - 'A'] = i;
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (startPts[i] < startPts[j] && endPts[i] < endPts[j] &&
          startPts[j] < endPts[i])
        pairs++;
    }
  }

  cout << pairs;
  return 0;
}
