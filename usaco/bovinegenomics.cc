#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int n, m, ans = 0;
string spot[100], plain[100];
map<char, int> idx = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};

int main() {

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> spot[i];
  for (int i = 0; i < n; i++)
    cin >> plain[i];

  for (int i = 0; i < m; i++) {
    bool isPotential = true;
    int spotCount[4], plainCount[4];
    fill_n(spotCount, 4, 0);
    fill_n(plainCount, 4, 0);

    for (int j = 0; j < n; j++) {
      spotCount[idx[spot[j][i]]]++;
      plainCount[idx[plain[j][i]]]++;
    }

    for (int k = 0; k < 4; k++)
      if (spotCount[k] > 0 && plainCount[k] > 0) {
        isPotential = false;
        break;
      }
    if (isPotential)
      ans++;
  }

  cout << ans << endl;
  return 0;
}
