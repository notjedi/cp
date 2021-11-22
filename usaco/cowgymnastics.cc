#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int main() {

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);
  int k, n, x, count = 0;
  cin >> k >> n;
  int ranks[n][n];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      ranks[i][x - 1] = j;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      bool consistent = true;
      for (int t = 0; t < k; t++) {
        if (ranks[t][i] > ranks[t][j]) {
          consistent = false;
          break;
        }
      }
      if (consistent)
        count++;
    }
  }

  cout << count << endl;
  return 0;
}
