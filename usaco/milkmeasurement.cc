#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

bool onBoard[3] = {false, false, false};
tuple<int, char, int> info[100];
int outputs[3] = {7, 7, 7};
int ans = 0;

bool sortTuple(tuple<int, char, int> a, tuple<int, char, int> b) {
  return get<0>(a) < get<0>(b);
}

int main() {

  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int day, output;
    string name;
    cin >> day >> name >> output;
    info[i] = make_tuple(day, name[0], output);
  }
  sort(info, info + n, sortTuple);

  for (int i = 0; i < n; i++) {
    auto entry = info[i];
    char name = get<1>(entry);
    int amount = get<2>(entry);

    if (name == 'B')
      outputs[0] += amount;
    else if (name == 'E')
      outputs[1] += amount;
    else if (name == 'M')
      outputs[2] += amount;

    int currMax = max({outputs[0], outputs[1], outputs[2]});
    bool tempOnBoard[3];
    for (int i = 0; i < 3; i++)
      tempOnBoard[i] = (outputs[i] == currMax);
    for (int i = 0; i < 3; i++)
      if (onBoard[i] != tempOnBoard[i]) {
        ans++;
        break;
      }
    for (int i = 0; i < 3; i++)
      onBoard[i] = tempOnBoard[i];
  }

  cout << ans;
  return 0;
}
