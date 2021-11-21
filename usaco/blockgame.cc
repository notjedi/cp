#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int charCount[26];

void solve(string a, string b) {
  int aCount[26], bCount[26];
  fill_n(aCount, 26, 0);
  fill_n(bCount, 26, 0);
  for (char c : a)
    aCount[c - 'a']++;
  for (char c : b)
    bCount[c - 'a']++;
  for (int i = 0; i < 26; i++)
    charCount[i] += max(aCount[i], bCount[i]);
}

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=664 */
int main() {

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int n;
  string a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    solve(a, b);
  }

  for (int i = 0; i < 26; i++)
    cout << charCount[i] << endl;
  return 0;
}
