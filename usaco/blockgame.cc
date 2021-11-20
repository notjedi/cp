#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int charCount[26], seen[26];

void solve(string a) {
  for (char c : a) {
    if (!seen[c - 'a']) {
      charCount[c - 'a']++;
      seen[c - 'a'] = 1;
    }
  }
}

/* http : // www.usaco.org/index.php?page=viewproblem2&cpid=664 */
int main() {

  int n;
  string a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    fill_n(seen, 26, 0);
    cin >> a >> b;
    solve(a);
    solve(b);
  }

  for (int i = 0; i < 26; i++)
    cout << charCount[i] << endl;
  return 0;
}
