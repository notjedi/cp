#include <bits/stdc++.h>

using namespace std;

int main() {
  set<string> attacks;
  string r1, k1, temp;
  cin >> r1 >> k1;

  temp = r1;
  for (char i = 'a'; i <= 'h'; i++) {
    temp[0] = i;
    attacks.insert(temp);
  }
  temp = r1;
  for (char i = '1'; i <= '8'; i++) {
    temp[1] = i;
    attacks.insert(temp);
  }

  attacks.insert(k1);
  for (int i : {2, -2, 1, -1}) {
    for (int j : {2, -2, 1, -1}) {
      if (abs(i) == abs(j))
        continue;
      temp = k1;
      temp[0] += i;
      temp[1] += j;
      if (temp[0] >= 'a' && temp[0] <= 'h')
        if (temp[1] >= '1' && temp[1] <= '8')
          attacks.insert(temp);
      temp = r1;
      temp[0] += i;
      temp[1] += j;
      if (temp[0] >= 'a' && temp[0] <= 'h')
        if (temp[1] >= '1' && temp[1] <= '8')
          attacks.insert(temp);
    }
  }

  cout << 64 - attacks.size();

  return 0;
}
