#include <iostream>

/* https://codeforces.com/problemset/problem/177/D1 */
using namespace std;
using ll = long long;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int a[n], b[m];

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  for (int i = 0; i < (n - m + 1); i++) {
    for (int j = 0; j < m; j++) {
      a[i + j] = (a[i + j] + b[j]) % c;
    }
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  return 0;
}
