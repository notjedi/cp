#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, m, k, sum = 0, MAX = 1e6 + 7;
  cin >> n >> m >> k;
  vector<int> resViablity(m, MAX);

  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    resViablity[r - 1] = min(resViablity[r - 1], c);
  }

  for (int i = 0; i < m; i++)
    if (resViablity[i] != MAX)
      sum += resViablity[i];

  cout << min(sum, k) << endl;
  return 0;
}
