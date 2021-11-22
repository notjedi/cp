#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

tuple<int, int, int> contact[250];
bool candidates[100];

/*
NOT WORKING, YET TO FINISH THIS PROBLEM
*/

int main() {

  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);
  int n, t, lb = 0, ub = 0, pzCount = 0;
  string infected;

  cin >> n >> t;
  cin >> infected;
  for (int i = 0; i < t; i++)
    cin >> get<0>(contact[i]) >> get<1>(contact[i]) >> get<2>(contact[i]);

  sort(contact, contact + t);
  fill_n(candidates, n, true);

  for (int i = 0; i < t; i++) {
    auto temp = contact[i];
    int x = get<1>(temp), y = get<2>(temp);
    if (!(infected[x - 1] == '1' && infected[y - 1] == '1')) {
      candidates[x - 1] = false;
      candidates[y - 1] = false;
    }
  }

  for (int i = 0; i < t; i++) {
    auto temp = contact[i];
    int x = get<1>(temp), y = get<2>(temp);
    if (candidates[x - 1] == true && infected[y - 1] == '1')
      lb++;
    else if (candidates[x - 1] == true && infected[y - 1] == '0')
      ub = max(0, lb);
  }

  for (int i = 0; i < t; i++)
    if (candidates[i])
      pzCount++;

  cout << pzCount << " " << lb << " " << (ub == 0 ? "Infinity" : to_string(ub))
       << endl;
  return 0;
}
