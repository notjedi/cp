#include <bits/stdc++.h>

using namespace std;

int main() {
  int flag = 0;
  string b1, b2, e1, e2, b, e, initial;
  cin >> b1 >> b2;
  cin >> e1 >> e2;
  swap(b2[0], b2[1]);
  swap(e2[0], e2[1]);

  b = b1 + b2;
  e = e1 + e2;
  initial = b;

  // room for imporevement tho
  // https://codeforces.com/blog/entry/43868
  do {
    if (b == e) {
      flag = 1;
      break;
    }

    for (int i = 0; i < 4; i++) {
      if (b[i] == 'X') {
        b[i] = b[(i + 1) % 4];
        b[(i + 1) % 4] = 'X';
        break;
      }
    }

  } while (b != initial);

  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
