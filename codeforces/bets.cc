#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, profit = 0;
  cin >> n >> m;
  int start[m], finish[m], time[m], prize[m];
  for (int i = 0; i < m; i++)
    cin >> start[i] >> finish[i] >> time[i] >> prize[i];

  for (int i = 1; i <= n; i++) {
    int maxProfit = 0, minTime = 1001, minTimeIdx = -1;
    for (int j = 0; j < m; j++) {
      if (start[j] <= i && finish[j] >= i)
        if (time[j] < minTime) {
          minTimeIdx = j;
          minTime = time[j];
        }
    }
    if (minTimeIdx != -1)
      profit += prize[minTimeIdx];
  }

  cout << profit << endl;
  return 0;
}
