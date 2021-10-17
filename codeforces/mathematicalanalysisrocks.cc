#include <iostream>

/* https://codeforces.com/problemset/problem/180/F */
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  /* gives note to best friend */
  /* 4 3 2 5 1  ans */

  /* 5 2 3 1 4  ques */
  /* 1 3 2 4 5  ques */

  /* 1 2 3 4 5 1st day */
  /* 5 3 2 1 4 2nd day */
  /* 5 2 3 1 4 3rd day */
  /* 1 3 2 4 5 */

  return 0;
}
